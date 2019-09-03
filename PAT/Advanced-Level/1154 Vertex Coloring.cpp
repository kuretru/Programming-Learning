#include <iostream>
#include <set>
#include <vector>
int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N);
    while (M--)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        data[x].push_back(y);
        data[y].push_back(x);
    }
    std::cin >> M;
    while (M--)
    {
        std::vector<int> color(N);
        std::set<int> count;
        for (int i = 0; i < N; i++)
        {
            std::cin >> color[i];
            count.insert(color[i]);
        }
        bool result = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < data[i].size(); j++)
            {
                if (color[i] == color[data[i][j]])
                {
                    i = N;
                    result = false;
                    break;
                }
            }
        }
        if (result)
            std::cout << count.size() << "-coloring" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    return 0;
}
