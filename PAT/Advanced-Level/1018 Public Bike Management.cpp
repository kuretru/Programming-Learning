// 仅在去的时候调整，因此必须同时维护带去及带回两个变量，例如需要5，3->2->10->10->10->0，会产生两者都不为0的情况

#include <iostream>
#include <vector>

using std::vector;

struct result
{
    int time = 0;
    int send = 0;
    int back = 0;
    vector<int> path;
};

bool compare(const result &x, const result &y);

void DFS(const vector<vector<int>> &data, const vector<int> &capacity, // 图论数据
         vector<bool> &visited, int start, int &end,                   // DFS辅助数据
         result &current, result &final);                              // 结论数据

int main()
{

    int C = 0, N = 0, S = 0, M = 0;
    std::cin >> C >> N >> S >> M;
    C >>= 1;
    vector<int> capacity(N + 1);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> capacity[i];
        capacity[i] -= C;
    }
    vector<vector<int>> data(N + 1, vector<int>(N + 1, -1));
    while (M--)
    {
        int x = 0, y = 0, time = 0;
        std::cin >> x >> y >> time;
        data[x][y] = data[y][x] = time;
    }

    vector<bool> visited(N, false);
    result current, final;
    final.time = INT32_MAX;
    DFS(data, capacity, visited, 0, S, current, final);

    std::cout << final.send << " 0";
    for (auto iter = final.path.begin() + 1; iter != final.path.end(); iter++)
        std::cout << "->" << *iter;
    std::cout << " " << final.back << std::endl;
    return 0;
}

bool compare(const result &x, const result &y)
{
    if (x.time != y.time)
        return x.time < y.time;
    if (x.send != y.send)
        return x.send < y.send;
    return x.back < y.back;
}

void DFS(const vector<vector<int>> &data, const vector<int> &capacity,
         vector<bool> &visited, int start, int &end,
         result &current, result &final)
{
    if (current.time > final.time)
        return;
    visited[start] = true;
    current.path.push_back(start);
    if (start == end)
    {
        current.send = 0;
        current.back = 0;
        for (auto iter = current.path.begin() + 1; iter != current.path.end(); iter++)
        {
            if (capacity[*iter] > 0 || current.back + capacity[*iter] > 0)
                current.back += capacity[*iter];
            else
            {
                current.send += (-capacity[*iter]) - current.back;
                current.back = 0;
            }
        }
        if (compare(current, final))
            final = current;
    }
    else
    {
        for (unsigned int i = 1; i < capacity.size(); i++)
        {
            if (visited[i] || data[start][i] == -1)
                continue;
            current.time += data[start][i];
            DFS(data, capacity, visited, i, end, current, final);
            current.time -= data[start][i];
        }
    }
    visited[start] = false;
    current.path.pop_back();
}
