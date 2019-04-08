#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct person
{
    std::string name;
    int year;
    int month;
    int day;
    bool operator<(const person x) const
    {
        if (this->year == x.year)
        {
            if (this->month == x.month)
                return this->day < x.day;
            return this->month < x.month;
        }
        return this->year < x.year;
    }
};
int main()
{
    std::vector<person> data;
    person min = {"min", 1814, 9, 5}, max = {"max", 2014, 9, 7};
    int count;
    std::cin >> count;
    while (count--)
    {
        person p;
        std::cin >> p.name;
        scanf("%d/%d/%d", &p.year, &p.month, &p.day);
        if (p < max && min < p)
            data.push_back(p);
    }
    std::sort(data.begin(), data.end());
    std::cout << data.size();
    if (data.size() > 0)
        std::cout << " " << data.front().name << " " << data.back().name;
    std::cout << std::endl;
    return 0;
}
