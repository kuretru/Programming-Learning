#include <iostream>
#include <set>
#include <vector>

struct edge
{
    int start;
    int end;
    int cost;
    bool operator<(const edge y) const
    {
        return cost < y.cost;
    }
};

void merge(std::vector<std::vector<edge>> &data, std::set<int> &connected, std::multiset<edge> &edges, int vertex)
{
    connected.insert(vertex);
    for (auto iter = data[vertex].begin(); iter != data[vertex].end(); iter++)
        edges.insert(*iter);
}

int main()
{
    int N, M, sum = 0;
    std::cin >> N >> M;
    std::vector<std::vector<edge>> data(N + 1);
    while (M--)
    {
        edge edge;
        std::cin >> edge.start >> edge.end >> edge.cost;
        data[edge.start].push_back(edge);
        data[edge.end].push_back(edge);
    }
    std::vector<edge> result;
    std::set<int> connected;
    std::multiset<edge> edges;
    merge(data, connected, edges, 1);
    while (!edges.empty())
    {
        edge edge = *edges.begin();
        edges.erase(edges.begin());
        if (connected.count(edge.start) && connected.count(edge.end))
            continue;
        result.push_back(edge);
        if (connected.count(edge.start))
            merge(data, connected, edges, edge.end);
        else if (connected.count(edge.end))
            merge(data, connected, edges, edge.start);
    }
    for (auto iter = result.begin(); iter != result.end(); iter++)
        sum += iter->cost;
    std::cout << (result.size() == N - 1 ? sum : -1) << std::endl;
    return 0;
}
