#include <iostream>

int main()
{
    int count = 0, floor = 0, n = 0;
    std::cin >> count;
    int result = count * 5;
    while (count--)
    {
        std::cin >> n;
        if (n > floor)
            result += (n - floor) * 6;
        else
            result += (floor - n) * 4;
        floor = n;
    }
    std::cout << result << std::endl;
    return 0;
}
