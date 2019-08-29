#include <iostream>
#include <set>
#include <vector>

struct edge
{
    int start = 0;
    int end = 0;
    edge(int start, int end)
    {
        if (start > end)
            std::swap(start, end);
        this->start = start;
        this->end = end;
    }
    bool operator<(const edge &y) const
    {
        if (start != y.start)
            return start < y.start;
        return end < y.end;
    }
};

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N);
    std::set<edge> edges;
    for (int i = 0; i < M; i++)
    {
        int start = 0, end = 0;
        std::cin >> start >> end;
        data[start].push_back(end);
        data[end].push_back(start);
        edges.insert(edge(start, end));
    }
    std::cin >> K;
    while (K--)
    {
        int count = 0, start = 0;
        std::cin >> count;
        std::set<edge> connected;
        while (count--)
        {
            std::cin >> start;
            for (int end : data[start])
                connected.insert(edge(start, end));
        }
        bool result = connected.size() == edges.size();
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
