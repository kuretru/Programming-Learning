#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct student
{
    std::string id;
    int grade, overall, location, local;
    bool operator<(const student &y) const
    {
        if (grade == y.grade)
            return id < y.id;
        return grade > y.grade;
    }
    student(int location)
    {
        this->location = location;
    }
};
int main()
{
    int location_number, count, last;
    std::cin >> location_number;
    std::vector<student> overall, local;
    std::vector<student>::iterator iter;
    for (int i = 1; i <= location_number; i++)
    {
        local.clear();
        std::cin >> count;
        while (count-- > 0)
        {
            student s(i);
            std::cin >> s.id >> s.grade;
            local.push_back(s);
        }
        std::sort(local.begin(), local.end());
        iter = local.begin();
        for (int i = 1, last = -1; iter != local.end(); iter++, i++)
        {
            if (iter->grade != last)
                iter->local = i;
            else
                iter->local = (iter - 1)->local;
            last = iter->grade;
        }
        overall.insert(overall.end(), local.begin(), local.end());
    }
    std::cout << overall.size() << std::endl;
    std::sort(overall.begin(), overall.end());
    iter = overall.begin();
    for (int i = 1, last = -1; iter != overall.end(); iter++, i++)
    {
        if (iter->grade != last)
            iter->overall = i;
        else
            iter->overall = (iter - 1)->overall;
        last = iter->grade;
        std::cout << iter->id << " " << iter->overall << " ";
        std::cout << iter->location << " " << iter->local << std::endl;
    }
    return 0;
}
