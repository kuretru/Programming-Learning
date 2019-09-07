#include <cmath>
#include <iostream>

bool isPrime(int number)
{
    int length = sqrt(number);
    for (int i = 2; i <= length; i++)
        if (number % i == 0)
            return false;
    return number > 1;
}

bool sexyPrime(int number)
{
    if (!isPrime(number))
        return false;
    if (isPrime(number - 6) || isPrime(number + 6))
        return true;
    return false;
}

int main()
{
    int number = 0, result = 0;
    std::cin >> number;
    if (sexyPrime(number))
    {
        if (isPrime(number - 6))
            result = number - 6;
        else
            result = number + 6;
        std::cout << "Yes" << std::endl;
    }
    else
    {
        for (int i = number + 1;; i++)
        {
            if (sexyPrime(i))
            {
                result = i;
                break;
            }
        }
        std::cout << "No" << std::endl;
    }
    std::cout << result << std::endl;
    return 0;
}
