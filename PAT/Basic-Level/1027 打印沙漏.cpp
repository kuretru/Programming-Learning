#include <cmath>
#include <iostream>
#include <string>

int main()
{
    int count = 0, n = 0, used = 0;
    std::string symbol;
    std::cin >> count >> symbol;
    for (int i = 1; used <= count; i += 2)
    {
        int increment = i == 1 ? i : i * 2;
        if (used + increment > count)
            break;
        used += increment;
        n++;
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= n - abs(n - i) - 1; j++)
            std::cout << " ";
        for (int j = 1; j <= 2 * (abs(n - i) + 1) - 1; j++)
            std::cout << symbol;
        std::cout << std::endl;
    }
    std::cout << count - used << std::endl;
    return 0;
}
