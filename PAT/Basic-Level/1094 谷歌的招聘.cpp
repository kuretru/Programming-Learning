#include <cmath>
#include <iostream>
#include <string>

int is_prime(int n)
{
    int length = sqrt(n);
    for (int i = 2; i <= length; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

int main()
{
    int L = 0, K = 0;
    std::string key = "";
    std::cin >> L >> K >> key;
    for (int i = 0; i <= L - K; i++)
    {
        std::string sub = key.substr(i, K);
        if (is_prime(std::stoi(sub)))
        {
            std::cout << sub << std::endl;
            return 0;
        }
    }
    std::cout << "404" << std::endl;
    return 0;
}
