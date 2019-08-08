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

int find(std::vector<int> &data, int key)
{
    if (data[key] < 0)
        return key;
    int result = find(data, data[key]);
    data[key] = result;
    return result;
}

void unionn(std::vector<int> &data, int root1, int root2)
{
    if (data[root1] < data[root2])
    {
        data[root1] += data[root2];
        data[root2] = root1;
    }
    else
    {
        data[root2] += data[root1];
        data[root1] = root2;
    }
}

int main()
{
    int N, M, sum = 0;
    std::cin >> N >> M;
    std::multiset<edge> edges;
    while (M--)
    {
        edge edge;
        std::cin >> edge.start >> edge.end >> edge.cost;
        edges.insert(edge);
    }
    std::vector<edge> result;
    std::vector<int> data(N + 1, -1);
    while (!edges.empty())
    {
        edge edge = *edges.begin();
        edges.erase(edges.begin());
        int root1 = find(data, edge.start);
        int root2 = find(data, edge.end);
        if (root1 != root2 || (root1 == -1 && root2 == -1))
        {
            unionn(data, root1, root2);
            result.push_back(edge);
        }
    }
    for (auto iter = result.begin(); iter != result.end(); iter++)
        sum += iter->cost;
    std::cout << (result.size() == N - 1 ? sum : -1) << std::endl;
    return 0;
}
