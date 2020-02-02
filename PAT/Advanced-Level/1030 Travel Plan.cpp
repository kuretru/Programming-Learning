#include <iostream>
#include <vector>

struct point
{
    int distance = INT32_MAX;
    int cost = INT32_MAX;
    bool visit = false;
    std::vector<int> path;
};

int main()
{
    int N = 0, M = 0, S = 0, D = 0;
    std::cin >> N >> M >> S >> D;
    std::vector<std::vector<int>> distance(N, std::vector<int>(N, INT32_MAX));
    std::vector<std::vector<int>> cost(N, std::vector<int>(N, INT32_MAX));
    while (M--)
    {
        int c1 = 0, c2 = 0, d = 0, c = 0;
        std::cin >> c1 >> c2 >> d >> c;
        distance[c1][c2] = distance[c2][c1] = d;
        cost[c1][c2] = cost[c2][c1] = c;
    }
    std::vector<point> dis(N);
    dis[S].distance = dis[S].cost = 0;
    dis[S].visit = true;
    for (int i = 0; i < N; i++)
    {
        if (distance[S][i] != INT32_MAX)
        {
            dis[i].distance = distance[S][i];
            dis[i].cost = cost[S][i];
            dis[i].path.push_back(S);
            dis[i].path.push_back(i);
        }
    }
    while (true)
    {
        int min = INT32_MAX, index;
        for (int i = 0; i < N; i++)
        {
            if (!dis[i].visit && dis[i].distance < min)
            {
                min = dis[i].distance;
                index = i;
            }
        }
        if (min == INT32_MAX)
            break;
        dis[index].visit = true;
        for (int i = 0; i < N; i++)
        {
            if (distance[index][i] == INT32_MAX)
                continue;
            int diss = dis[index].distance + distance[index][i];
            int coss = dis[index].cost + cost[index][i];
            if (diss < dis[i].distance || (i == D && diss == dis[i].distance && coss < dis[i].cost))
            {
                dis[i].distance = diss;
                dis[i].cost = coss;
                dis[i].path.clear();
                dis[i].path.insert(dis[i].path.end(), dis[index].path.begin(), dis[index].path.end());
                dis[i].path.push_back(i);
            }
        }
    }
    for (auto iter = dis[D].path.begin(); iter != dis[D].path.end(); iter++)
        std::cout << *iter << " ";
    std::cout << dis[D].distance << " " << dis[D].cost << std::endl;
    return 0;
}
