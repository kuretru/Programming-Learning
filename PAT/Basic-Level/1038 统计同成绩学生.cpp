#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::map<int, int> data;
    int count = 0, key = 0;
    std::cin >> count;
    while (count--)
    {
        std::cin >> key;
        data[key]++;
    }
    std::cin >> count;
    for (int i = 0; i < count; i++)
    {
        std::cin >> key;
        std::cout << data[key] << (i != count - 1 ? " " : "\n");
    }
    return 0;
}
