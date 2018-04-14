#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    for (int i = 100; i > 0; i /= 10)
    {
        for (int j = 1; j <= n / i % 10; j++)
        {
            if (i == 100)
                std::cout << "B";
            else if (i == 10)
                std::cout << "S";
            else
                std::cout << j;
        }
    }
    return 0;
}
