#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::vector;

void DFS(const vector<set<int>> &data, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (auto iter = data[node].begin(); iter != data[node].end(); iter++)
        if (!visited[*iter])
            DFS(data, visited, *iter);
}

void find_deepest(const vector<set<int>> &data, vector<bool> &visited,
                  int node, int height, int &max_height, set<int> &result)
{
    visited[node] = true;
    bool found_deeper = false;
    for (auto iter = data[node].begin(); iter != data[node].end(); iter++)
    {
        if (!visited[*iter])
        {
            find_deepest(data, visited, *iter, height + 1, max_height, result);
            found_deeper = true;
        }
    }
    if (!found_deeper && height >= max_height)
    {
        if (height > max_height)
        {
            max_height = height;
            result.clear();
        }
        result.insert(node);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, components = 0;
    std::cin >> N;
    vector<set<int>> data(N + 1);
    for (int i = 1; i < N; i++)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        data[x].insert(y);
        data[y].insert(x);
    }
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;
        components++;
        DFS(data, visited, i);
    }
    if (components > 1)
        std::cout << "Error: " << components << " components" << std::endl;
    else
    {
        set<int> result, tmp;
        for (int i = 0; i < 2; i++)
        {
            int begin = i == 0 ? 1 : *result.begin(), deepest = 0;
            visited.assign(N + 1, false);
            tmp.clear();
            find_deepest(data, visited, begin, 1, deepest, tmp);
            result.insert(tmp.begin(), tmp.end());
        }
        for (auto iter = result.begin(); iter != result.end(); iter++)
            std::cout << *iter << std::endl;
    }
    return 0;
}
