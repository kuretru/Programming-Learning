#include <iostream>
#include <set>
#include <vector>

struct edge
{
    int cost = -1;
    int margin = -1;
};

struct vertex
{
    int earliest = 0;
    int latest = INT32_MAX;
    int inDgree = 0;
    int outDgree = 0;
};

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<vertex> vertexes(N + 1);
    std::vector<std::vector<edge>> data(N + 1, (std::vector<edge>(N + 1)));
    while (M--)
    {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        data[start][end].cost = cost;
        vertexes[start].outDgree++;
        vertexes[end].inDgree++;
    }

    int maxEarliest = 0;
    for (std::set<int> found; found.size() < N;)
    {
        int last = found.size();
        for (int i = 1; i <= N; i++)
        {
            if (vertexes[i].inDgree > 0 || found.count(i))
                continue;
            found.insert(i);
            for (int j = 1; j <= N; j++)
            {
                if (data[i][j].cost == -1)
                    continue;
                vertexes[j].earliest = std::max(vertexes[j].earliest, vertexes[i].earliest + data[i][j].cost);
                vertexes[j].inDgree--;
                maxEarliest = std::max(maxEarliest, vertexes[j].earliest); // 顺便求整个图的最早完成时间
            }
        }
        if (last == found.size())
        {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    std::cout << maxEarliest << std::endl;

    // 多终点时，所有终点的最迟完成时间都设为最大值
    for (int i = N; i >= 1; i--)
        if (!vertexes[i].outDgree)
            vertexes[i].latest = maxEarliest;
    for (std::set<int> found; found.size() < N;)
    {
        for (int i = N; i >= 1; i--)
        {
            if (vertexes[i].outDgree > 0 || found.count(i))
                continue;
            found.insert(i);
            for (int j = 1; j <= N; j++)
            {
                if (data[j][i].cost == -1)
                    continue;
                vertexes[j].latest = std::min(vertexes[j].latest, vertexes[i].latest - data[j][i].cost);
                vertexes[j].outDgree--;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = N; j >= 1; j--)
        {
            if (data[i][j].cost == -1)
                continue;
            data[i][j].margin = vertexes[j].latest - vertexes[i].earliest - data[i][j].cost;
            if (!data[i][j].margin)
                std::cout << i << "->" << j << std::endl;
        }
    }
    return 0;
}
