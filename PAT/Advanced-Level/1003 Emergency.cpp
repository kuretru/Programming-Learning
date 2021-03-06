#include <iostream>
#include <vector>

using std::vector;

struct city
{
    int distance = INT32_MAX;
    int paths = 0;
    int teams = 0;
    bool visited = false;
};

int main()
{
    int N = 0, M = 0, C1 = 0, C2 = 0, result = 0;
    std::cin >> N >> M >> C1 >> C2;
    vector<int> teams(N);
    for (int i = 0; i < N; i++)
        std::cin >> teams[i];
    vector<vector<int>> distance(N, vector<int>(N, INT32_MAX));
    while (M--)
    {
        int x = 0, y = 0, d = 0;
        std::cin >> x >> y >> d;
        distance[x][y] = distance[y][x] = d;
    }
    vector<city> dis(N);
    dis[C1].distance = 0;
    dis[C1].paths = 1;
    dis[C1].teams = teams[C1];
    dis[C1].visited = true;
    for (int i = 0; i < N; i++)
    {
        if (distance[C1][i] != INT32_MAX)
        {
            dis[i].distance = distance[C1][i];
            dis[i].paths = 1;
            dis[i].teams = teams[C1] + teams[i];
        }
    }
    while (true)
    {
        int min = INT32_MAX, index;
        for (int i = 0; i < N; i++)
        {
            if (!dis[i].visited && dis[i].distance < min)
            {
                min = dis[i].distance;
                index = i;
            }
        }
        if (min == INT32_MAX)
            break;
        dis[index].visited = true;
        for (int i = 0; i < N; i++)
        {
            if (distance[index][i] == INT32_MAX)
                continue;
            int diss = dis[index].distance + distance[index][i];
            if (diss < dis[i].distance)
            {
                dis[i].distance = diss;
                dis[i].paths = dis[index].paths;
                dis[i].teams = dis[index].teams + teams[i];
            }
            else if (diss == dis[i].distance)
            {
                dis[i].paths += dis[index].paths;
                if (dis[index].teams + teams[i] > dis[i].teams)
                    dis[i].teams = dis[index].teams + teams[i];
            }
        }
    }
    std::cout << dis[C2].paths << " " << dis[C2].teams << std::endl;
    return 0;
}
