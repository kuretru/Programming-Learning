#include <iostream>
#include <set>
#include <string>
#include <vector>

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
    int N = 0, low = 0, high = 0;
    std::cin >> N;
    std::vector<student> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i].name >> data[i].id >> data[i].grade;
    std::cin >> low >> high;
    std::set<student> result;
    for (student s : data)
        if (low <= s.grade && s.grade <= high)
            result.insert(s);
    if (result.empty())
        std::cout << "NONE" << std::endl;
    else
        for (auto iter = result.begin(); iter != result.end(); iter++)
            std::cout << iter->name << " " << iter->id << std::endl;
    return 0;
}
