#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::map<int, std::vector<int>> data;
    while (N--)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        data[x].push_back(y);
        data[y].push_back(x);
    }
    while (M--)
    {
        std::set<int> goods;
        bool result = true;
        int x = 0, y = 0;
        std::cin >> x;
        while (x--)
        {
            std::cin >> y;
            goods.insert(y);
        }
        for (auto i = goods.begin(); result && i != goods.end(); i++)
            for (auto j = data[*i].begin(); result && j != data[*i].end(); j++)
                if (goods.count(*j))
                    result = false;
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
