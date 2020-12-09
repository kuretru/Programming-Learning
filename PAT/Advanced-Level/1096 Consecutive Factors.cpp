#include <cmath>
#include <iostream>

int main()
{
    int N = 0, begin = 0, max = 0;
    std::cin >> N;
    int length = sqrt(N) + 1;
    for (int i = 2; i <= length; i++)
    {
        if (N % i != 0)
            continue;
        int tmp = N / i, j = i + 1;
        for (; tmp >= j && tmp % j == 0; j++)
            tmp /= j;
        if (j - i > max)
        {
            begin = i;
            max = j - i;
        }
    }
    if (max == 0)
    {
        std::cout << 1 << std::endl << N << std::endl;
        return 0;
    }
    std::cout << max << std::endl;
    for (int i = 0; i < max; i++)
        std::cout << begin + i << (i != max - 1 ? "*" : "\n");
    return 0;
}
