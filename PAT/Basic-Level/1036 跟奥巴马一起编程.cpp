#include <iostream>
#include <string>

int main()
{
    int count = 0;
    std::string symbol;
    std::cin >> count >> symbol;
    int end = count * 0.5 + 0.5;
    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (i == 0 || i == end - 1 || j == 0 || j == count - 1)
                std::cout << symbol;
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
