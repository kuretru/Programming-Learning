#include <iostream>
#include <set>
#include <string>

struct student
{
    std::string name = "";
    std::string id = "";
    int grade = 0;

    bool operator<(const student &y) const
    {
        return grade > y.grade;
    }
};

int main()
{
    int N = 0;
    std::string gender = "";
    std::cin >> N;
    std::set<student> boys, girls;
    while (N--)
    {
        student s;
        std::cin >> s.name >> gender >> s.id >> s.grade;
        if (gender == "M")
            boys.insert(s);
        else
            girls.insert(s);
    }
    if (girls.size() > 0)
        std::cout << girls.begin()->name << " " << girls.begin()->id << std::endl;
    else
        std::cout << "Absent" << std::endl;
    if (boys.size() > 0)
        std::cout << boys.rbegin()->name << " " << boys.rbegin()->id << std::endl;
    else
        std::cout << "Absent" << std::endl;
    if (girls.size() > 0 && boys.size() > 0)
        std::cout << girls.begin()->grade - boys.rbegin()->grade << std::endl;
    else
        std::cout << "NA" << std::endl;
    return 0;
}
