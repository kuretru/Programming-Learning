#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::vector;

struct auxiliary
{
    bool used = false;
    int cost = -1;
    auxiliary() {}
    auxiliary(int cost)
    {
        this->cost = cost;
    }
    bool operator<(const auxiliary &y) const
    {
        return cost < y.cost;
    }
    auxiliary operator+(const auxiliary &y)
    {
        return auxiliary(cost + y.cost);
    }
};

struct plan
{
    int index = 0;
    int min = INT32_MAX;
    int total = 0;
    bool operator<(const plan &y) const
    {
        if (min != y.min)
            return min > y.min;
        if (total != y.total)
            return total < y.total;
        return index < y.index;
    }
};

plan dijkstra(vector<vector<int>> &data, int N, int K, int start)
{
    // 初始化辅助数组
    vector<auxiliary> D(data.size());
    for (int i = 1; i < data.size(); i++)
        D[i].cost = data[start][i];
    D[start].used = true;

    for (int i = 2; i < data.size(); i++)
    {
        // 选择当前最短路径
        int min = 0;
        for (int i = 1; i < data.size(); i++)
        {
            if (D[i].used || D[i].cost == -1)
                continue;
            if (min == 0 || D[i] < D[min])
                min = i;
        }
        if (min == 0)
            break;
        D[min].used = true;

        // 如果经过当前最短路径去别的顶点有更短的路，则更新
        for (int i = 1; i < data.size(); i++)
        {
            if (D[i].used || data[min][i] == -1)
                continue;
            auxiliary newPath(data[min][i]);
            newPath = D[min] + newPath;
            if (D[i].cost == -1 || newPath < D[i])
                D[i] = newPath;
        }
    }

    plan result;
    result.index = start - N;
    for (int i = 1; i <= N; i++)
    {
        if (D[i].cost > K)
            D[i].cost = -1;
        if (D[i].cost < result.min)
            result.min = D[i].cost;
        result.total += D[i].cost;
    }
    return result;
}

int main()
{
    int N = 0, M = 0, D = 0, K = 0;
    std::cin >> N >> M >> D >> K;
    vector<vector<int>> data(N + M + 1, vector<int>(N + M + 1, -1));
    while (D--)
    {
        std::string P1 = "", P2 = "";
        int p1 = 0, p2 = 0, dist = 0;
        std::cin >> P1 >> P2 >> dist;
        p1 = P1[0] == 'G' ? std::stoi(P1.substr(1)) + N : std::stoi(P1);
        p2 = P2[0] == 'G' ? std::stoi(P2.substr(1)) + N : std::stoi(P2);
        data[p1][p2] = data[p2][p1] = dist;
    }
    std::set<plan> result;
    for (int i = N + 1; i <= N + M; i++)
    {
        plan record = dijkstra(data, N, K, i);
        if (record.min > 0)
            result.insert(record);
    }
    if (result.empty())
        std::cout << "No Solution" << std::endl;
    else
        printf("G%d\n%.1lf %.1lf\n", result.begin()->index, (double)result.begin()->min, result.begin()->total * 1.0 / N);
    return 0;
}
