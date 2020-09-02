#include <iostream>

int get_digit(int n)
{
    int result = 1;
    while (n > 0)
    {
        result *= 10;
        n /= 10;
    }
    return result;
}

int main()
{
    int M = 0, K = 0;
    std::cin >> M;
    while (M--)
    {
        std::cin >> K;
        for (int i = 1; i <= 10; i++)
        {
            if (i == 10)
                std::cout << "No" << std::endl;
            int pow = get_digit(K);
            if (i * K * K % pow == K)
            {
                std::cout << i << " " << i * K * K << std::endl;
                break;
            }
        }
    }
    return 0;
}
