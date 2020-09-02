#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct person
{
    std::string name = "";
    int year = 0;
    int month = 0;
    int day = 0;

    bool operator<(const person y) const
    {
        if (this->year != y.year)
            return this->year < y.year;
        if (this->month != y.month)
            return this->month < y.month;
        return this->day < y.day;
    }
};

const person min = {"min", 1814, 9, 5}, max = {"max", 2014, 9, 7};

int main()
{
    std::vector<person> data;
    int count = 0;
    std::cin >> count;
    while (count--)
    {
        person p;
        std::cin >> p.name;
        scanf("%d/%d/%d", &p.year, &p.month, &p.day);
        if (min < p && p < max)
            data.push_back(p);
    }
    std::sort(data.begin(), data.end());
    std::cout << data.size();
    if (data.size() > 0)
        std::cout << " " << data.front().name << " " << data.back().name;
    std::cout << std::endl;
    return 0;
}
