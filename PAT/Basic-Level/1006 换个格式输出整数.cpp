#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int hundreds = n / 100;
    int tens = n / 10 % 10;
    int ones = n % 10;
    while (hundreds--)
        std::cout << "B";
    while (tens--)
        std::cout << "S";
    for (int i = 1; i <= ones; i++)
        std::cout << i;
    std::cout << std::endl;
    return 0;
}
