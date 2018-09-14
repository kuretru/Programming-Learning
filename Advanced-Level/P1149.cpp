#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
int main()
{
    int N, M, x, y;
    std::cin >> N >> M;
    std::map<int, std::vector<int>> data;
    while (N--)
    {
        std::cin >> x >> y;
        data[x].push_back(y);
        data[y].push_back(x);
    }
    while (M--)
    {
        bool result = true;
        std::vector<int> goods;
        std::cin >> x;
        while (x--)
        {
            std::cin >> y;
            goods.push_back(y);
        }
        for (auto i = goods.begin(); result && i != goods.end(); i++)
            for (auto j = data[*i].begin(); result && j != data[*i].end(); j++)
                if (std::find(goods.begin(), goods.end(), *j) != goods.end())
                    result = false;
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
