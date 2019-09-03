#include <iostream>
#include <set>
#include <vector>

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N + 1, std::vector<int>(N + 1, -1));
    while (M--)
    {
        int city1 = 0, city2 = 0, dist = 0;
        std::cin >> city1 >> city2 >> dist;
        data[city1][city2] = data[city2][city1] = dist;
    }
    int minId = -1, min = INT32_MAX;
    std::cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int count = 0, type = 2, result = 0;
        std::cin >> count;
        std::vector<int> path(count);
        std::set<int> visited;
        for (int j = 0; j < count; j++)
        {
            std::cin >> path[j];
            visited.insert(path[j]);
        }
        for (int j = 1; j < count; j++)
        {
            if (result == -1)
                break;
            int x = path[j - 1], y = path[j];
            if (data[x][y] != -1)
                result += data[x][y];
            else
                result = -1;
        }
        if (visited.size() == N)
        {
            if (path.size() == N + 1)
                type = 0;
            else
                type = 1;
            if (result < min && result != -1)
            {
                minId = i;
                min = result;
            }
        }
        if (result == -1 || path[0] != path[count - 1])
            type = 2;

        if (result == -1)
            printf("Path %d: NA ", i);
        else
            printf("Path %d: %d ", i, result);
        if (type == 0)
            puts("(TS simple cycle)");
        else if (type == 1)
            puts("(TS cycle)");
        else if (type == 2)
            puts("(Not a TS cycle)");
    }
    printf("Shortest Dist(%d) = %d\n", minId, min);
    return 0;
}
