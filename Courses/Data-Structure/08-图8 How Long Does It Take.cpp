#include <iostream>
#include <vector>

struct edge
{
    int to = 0;
    int cost = 0;
    int margin = 0;
    edge(int to, int cost)
    {
        this->to = to;
        this->cost = cost;
    }
};

struct vertex
{
    int earliest = 0;
    int latest = 0;
    int inDegree = 0;
    std::vector<edge> edges;
};

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<vertex> data(N);
    while (M--)
    {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        data[start].edges.push_back(edge(end, cost));
        data[end].inDegree++;
    }
    int found = 0;
    int last = -1;
    while (found < N)
    {
        int origin = last;
        for (int i = 0; i < N; i++)
        {
            if (data[i].inDegree != 0)
                continue;
            data[i].inDegree--;
            found++;
            last = i;
            for (int j = 0; j < data[i].edges.size(); j++)
            {
                int end = data[i].edges[j].to;
                int cost = data[i].edges[j].cost + data[i].earliest;
                data[end].inDegree--;
                data[end].earliest = std::max(data[end].earliest, cost);
            }
        }
        if (origin == last)
        {
            std::cout << "Impossible" << std::endl;
            return 0;
        }
    }
    std::cout << data[last].earliest << std::endl;
    return 0;
}
