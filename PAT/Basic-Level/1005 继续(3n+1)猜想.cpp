#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main()
{
    int count = 0;
    std::cin >> count;
    std::vector<int> data(count), result;
    for (int i = 0; i < count; i++)
        std::cin >> data[i];
    std::sort(data.rbegin(), data.rend());
    std::map<int, bool> flags;
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        int tmp = *iter;
        while (tmp != 1)
        {
            if (tmp % 2 == 0)
                tmp /= 2;
            else
                tmp = (3 * tmp + 1) / 2;
            if (flags[tmp])
                break;
            else
                flags[tmp] = true;
        }
    }
    for (auto iter = data.begin(); iter != data.end(); iter++)
        if (!flags[*iter])
            result.push_back(*iter);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
