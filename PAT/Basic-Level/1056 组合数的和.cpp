#include <iostream>

int main()
{
    int count = 0, n = 0, sum = 0;
    std::cin >> count;
    for (int i = 0; i < count; i++)
    {
        std::cin >> n;
        sum += n;
    }
    sum *= 11 * (count - 1);
    std::cout << sum << std::endl;
    return 0;
}
