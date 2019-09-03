#include <cmath>
#include <iostream>
#include <string>

bool isPrime(int number)
{
    if (number < 2)
        return false;
    if (number != 2 && number % 2 == 0)
        return false;
    if (number != 3 && number % 3 == 0)
        return false;
    if (number != 5 && number % 5 == 0)
        return false;
    if (number != 7 && number % 7 == 0)
        return false;
    int length = std::sqrt(number);
    for (int i = 11; i < length; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    int L = 0, K = 0;
    std::string key = "";
    std::cin >> L >> K >> key;
    for (int i = 0; i <= L - K; i++)
    {
        std::string sub = key.substr(i, K);
        if (isPrime(std::stoi(sub)))
        {
            std::cout << sub << std::endl;
            return 0;
        }
    }
    std::cout << "404" << std::endl;
    return 0;
}
