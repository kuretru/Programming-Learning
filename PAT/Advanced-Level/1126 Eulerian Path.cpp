#include <iostream>
#include <set>
#include <vector>

using std::vector;

void DFS(vector<vector<int>> &data, int index, std::set<int> &vertices)
{
    vertices.insert(index);
    for (int i : data[index])
        if (!vertices.count(i))
            DFS(data, i, vertices);
}

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    vector<vector<int>> data(N + 1);
    while (M--)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        data[x].push_back(y);
        data[y].push_back(x);
    }
    int even = 0, odd = 0;
    for (int i = 1; i <= N; i++)
    {
        int count = data[i].size();
        if (count % 2 == 0)
            even++;
        else
            odd++;
        std::cout << count << (i != N ? " " : "\n");
    }
    std::set<int> vertices;
    DFS(data, 1, vertices);
    bool connected = N == (int)vertices.size();
    if (connected && even == N)
        std::cout
            << "Eulerian" << std::endl;
    else if (connected && odd == 2)
        std::cout << "Semi-Eulerian" << std::endl;
    else
        std::cout << "Non-Eulerian" << std::endl;
    return 0;
}
