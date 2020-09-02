#include <iostream>
#include <map>

int main()
{
    std::map<int, int> data;
    int count = 0, n = 0;
    std::cin >> count;
    for (int i = 1; i <= count; i++)
    {
        std::cin >> n;
        n -= i;
        n = n > 0 ? n : -n;
        data[n]++;
    }
    for (auto iter = data.rbegin(); iter != data.rend(); iter++)
        if (iter->second > 1)
            std::cout << iter->first << " " << iter->second << std::endl;
    return 0;
}
