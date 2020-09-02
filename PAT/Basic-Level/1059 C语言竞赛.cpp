#include <cmath>
#include <iostream>
#include <map>
#include <string>

struct player
{
    std::string name = "";
    std::string award = "";
    int rank = 0;
};

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
    std::map<std::string, player> data;
    int count = 0, rank = 1;
    std::cin >> count;
    while (count--)
    {
        player p;
        std::cin >> p.name;
        p.rank = rank++;
        if (p.rank == 1)
            p.award = "Mystery Award";
        else if (is_prime(p.rank))
            p.award = "Minion";
        else
            p.award = "Chocolate";
        data[p.name] = p;
    }
    std::cin >> count;
    while (count--)
    {
        std::string name = "";
        std::cin >> name;
        std::cout << name << ": ";
        if (data[name].rank > 0)
        {
            std::cout << data[name].award << std::endl;
            data[name].award = "Checked";
        }
        else
            std::cout << "Are you kidding?" << std::endl;
    }
    return 0;
}
