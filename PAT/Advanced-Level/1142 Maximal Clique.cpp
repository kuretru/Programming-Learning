#include <iostream>
#include <set>
#include <vector>

using std::vector;

int solve(vector<vector<int>> &data, std::set<int> &vertices)
{
    for (int i : vertices)
        for (int j : vertices)
            if (data[i][j] == 0)
                return 0;
    std::vector<int> remains;
    for (unsigned int i = 1; i < data.size(); i++)
        if (!vertices.count(i))
            remains.push_back(i);
    for (int i : remains)
    {
        int count = 0;
        for (int j : vertices)
            if (data[i][j] == 1)
                count++;
        if (count == vertices.size())
            return 2;
    }
    return 1;
}

int main()
{
    int Nv = 0, Ne = 0, M = 0;
    std::cin >> Nv >> Ne;
    vector<vector<int>> data(Nv + 1, vector<int>(Nv + 1, 0));
    while (Ne--)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        data[x][y] = data[y][x] = 1;
    }
    for (int i = 1; i <= Nv; i++)
        data[i][i] = 1;
    std::cin >> M;
    while (M--)
    {
        int K = 0, vertex = 0;
        std::cin >> K;
        std::set<int> vertices;
        for (int i = 0; i < K; i++)
        {
            std::cin >> vertex;
            vertices.insert(vertex);
        }
        int result = solve(data, vertices);
        if (result == 1)
            std::cout << "Yes" << std::endl;
        else if (result == 2)
            std::cout << "Not Maximal" << std::endl;
        else if (result == 0)
            std::cout << "Not a Clique" << std::endl;
    }
    return 0;
}
