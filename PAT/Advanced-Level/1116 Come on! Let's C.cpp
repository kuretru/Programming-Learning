#include <cmath>
#include <iostream>
#include <map>
#include <string>

bool isPrime(int number)
{
    int length = sqrt(number);
    for (int i = 2; i <= length; i++)
        if (number % i == 0)
            return false;
    return number > 2;
}

int main()
{
    std::string key;
    int N, K;
    std::cin >> N;
    std::map<std::string, int> rank;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> key;
        rank[key] = i;
    }
    std::cin >> K;
    while (K--)
    {
        std::cin >> key;
        std::cout << key << ": ";
        if (!rank.count(key))
            std::cout << "Are you kidding?" << std::endl;
        else if (rank[key] == -1)
            std::cout << "Checked" << std::endl;
        else if (rank[key] == 1)
            std::cout << "Mystery Award" << std::endl;
        else if (isPrime(rank[key]))
            std::cout << "Minion" << std::endl;
        else
            std::cout << "Chocolate" << std::endl;
        if (rank.count(key))
            rank[key] = -1;
    }
    return 0;
}
