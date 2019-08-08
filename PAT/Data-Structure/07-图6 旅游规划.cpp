#include <iostream>
#include <vector>

struct path
{
    int distance = INT32_MAX;
    int cost = INT32_MAX;
    bool operator<(const path y) const
    {
        if (distance == y.distance)
            return cost < y.cost;
        return distance < y.distance;
    }
};

struct auxiliary
{
    path p;
    bool used = false;
};

int findMin(std::vector<auxiliary> data)
{
    int result = -1;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].used)
            continue;
        if (result == -1 || data[i].p < data[result].p)
            result = i;
    }
    return result;
}

int main()
{
    int N, M, S, D;
    std::cin >> N >> M >> S >> D;
    std::vector<std::vector<path>> data(N, std::vector<path>(N));
    while (M--)
    {
        int c1, c2, distance, cost;
        std::cin >> c1 >> c2 >> distance >> cost;
        data[c1][c2].distance = data[c2][c1].distance = distance;
        data[c1][c2].cost = data[c2][c1].cost = cost;
    }
    std::vector<auxiliary> result(N);
    for (int i = 0; i < N; i++)
        result[i].p = data[S][i];
    result[S].used = true;
    while (true)
    {
        int min = findMin(result);
        if (min < 0)
            break;
        result[min].used = true;
        for (int i = 0; i < N; i++)
        {
            // 设成最大值会导致后续相加产生溢出变为负数的bug
            if (result[i].used || data[min][i].distance == INT32_MAX)
                continue;
            path p = result[min].p;
            p.distance += data[min][i].distance;
            p.cost += data[min][i].cost;
            if (p < result[i].p)
                result[i].p = p;
        }
    }
    std::cout << result[D].p.distance << " " << result[D].p.cost << std::endl;
    return 0;
}
