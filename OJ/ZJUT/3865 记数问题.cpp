#include <iostream>

int main()
{
    int n = 0, x = 0, result = 0;
    std::cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int number = i; number > 0; number /= 10)
        {
            if (number % 10 == x)
                result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
