#include <iostream>

int main()
{
    int n, result = 0;
    std::cin >> n;
    while (n > 1)
    {
        if (n % 2 == 0)
            n >>= 1;
        else
            n = (n * 3 + 1) >> 1;
        result++;
    }
    std::cout << result << std::endl;
    return 0;
}
