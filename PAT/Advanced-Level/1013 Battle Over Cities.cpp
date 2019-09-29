#include <iostream>
#include <vector>

struct edge
{
    int start = 0, end = 0;
};

int find(std::vector<int> &data, int value)
{
    if (data[value] < 0)
        return value;
    int result = find(data, data[value]);
    data[value] = result;
    return result;
}

void unionn(std::vector<int> &data, int root1, int root2)
{
    root1 = find(data, root1);
    root2 = find(data, root2);
    if (root1 == root2)
        return;
    if (root1 > root2)
    {
        data[root2] += data[root1];
        data[root1] = root2;
    }
    else
    {
        data[root1] += data[root2];
        data[root2] = root1;
    }
}

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M >> K;
    std::vector<edge> edges;
    while (M--)
    {
        edge e;
        std::cin >> e.start >> e.end;
        edges.push_back(e);
    }
    while (K--)
    {
        std::vector<int> data(N + 1, -1);
        int fallen = 0, count = 0;
        std::cin >> fallen;
        for (edge e : edges)
        {
            if (e.start == fallen || e.end == fallen)
                continue;
            unionn(data, e.start, e.end);
        }
        for (int i = 1; i <= N; i++)
            if (i != fallen && data[i] < 0)
                count++;
        std::cout << count - 1 << std::endl;
    }
    return 0;
}
