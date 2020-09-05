#include <algorithm>
#include <iostream>
#include <vector>

void input(std::vector<int> *data)
{
    int count = 0, tmp = 0;
    std::cin >> count;
    while (count--)
    {
        std::cin >> tmp;
        if (tmp >= 0)
            data[0].push_back(tmp);
        else
            data[1].push_back(tmp);
    }
    std::sort(data[0].rbegin(), data[0].rend());
    std::sort(data[1].begin(), data[1].end());
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<int> *coupons = new std::vector<int>[2];
    std::vector<int> *products = new std::vector<int>[2];
    input(coupons);
    input(products);
    int result = 0;
    for (int i = 0; i < 2; i++)
    {
        int length = std::min(coupons[i].size(), products[i].size());
        for (int j = 0; j < length; j++)
            result += coupons[i][j] * products[i][j];
    }
    std::cout << result << std::endl;
    return 0;
}
