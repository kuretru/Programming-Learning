#include <iostream>
int main()
{
    int K, tmp, sum = 0, result = 0;
    std::cin >> K;
    while (K--)
    {
        std::cin >> tmp;
        sum += tmp;
        if (sum > result)
            result = sum;
        if (sum < 0)
            sum = 0;
    }
    std::cout << result << std::endl;
    return 0;
}
