#include <iostream>
#include <string>
int main()
{
    std::string number;
    std::cin >> number;
    if (number[0] == '-')
        std::cout << "-";
    int E = number.find("E");
    int exp = std::stoi(number.substr(E + 1));
    number = number.substr(1, E - 1).erase(1, 1);
    if (exp < 0)
    {
        std::cout << "0.";
        for (++exp; exp < 0; exp++)
            std::cout << "0";
        std::cout << number;
    }
    else
    {
        for (int i = 0; i < number.length(); i++, exp--)
        {
            std::cout << number[i];
            if (exp == 0 && i != number.length() - 1)
                std::cout << ".";
        }
        for (++exp; exp > 0; exp--)
            std::cout << "0";
    }
    std::cout << std::endl;
    return 0;
}
