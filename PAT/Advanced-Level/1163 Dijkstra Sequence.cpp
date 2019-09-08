#include <iostream>
#include <vector>

using std::vector;

struct auxiliary
{
    bool used = false;
    int cost = -1;
};

bool dijkstra(vector<vector<int>> &data, vector<int> sequence, int N)
{
    int start = sequence[0];
    vector<auxiliary> D(N + 1);
    for (int i = 1; i <= N; i++)
        D[i].cost = data[start][i];
    D[start].used = true;
    for (int i = 1; i < N; i++)
    {
        int min = 0;
        for (int j = 1; j <= N; j++)
        {
            if (D[j].used || D[j].cost == -1)
                continue;
            if (min == 0 || D[j].cost < D[min].cost)
                min = j;
        }
        if (min != sequence[i])
        {
            if (D[sequence[i]].used)
                return false;
            if (D[min].cost != D[sequence[i]].cost)
                return false;
            min = sequence[i];
        }
        D[min].used = true;
        for (int j = 1; j <= N; j++)
        {
            if (D[j].used || data[min][j] == -1)
                continue;
            if (D[j].cost == -1 || D[min].cost + data[min][j] < D[j].cost)
            {
                D[j].cost = D[min].cost + data[min][j];
            }
        }
    }
    return true;
}

int main()
{
    int Nv = 0, Ne = 0, K = 0;
    std::cin >> Nv >> Ne;
    vector<vector<int>> data(Nv + 1, vector<int>(Nv + 1, -1));
    while (Ne--)
    {
        int start = 0, end = 0, cost = 0;
        std::cin >> start >> end >> cost;
        data[start][end] = data[end][start] = cost;
    }
    std::cin >> K;
    while (K--)
    {
        vector<int> sequence(Nv);
        for (int i = 0; i < Nv; i++)
            std::cin >> sequence[i];
        bool result = dijkstra(data, sequence, Nv);
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
