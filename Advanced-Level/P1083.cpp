#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct student
{
    std::string name, id;
    int grade;
    bool operator<(const student &y) const
    {
        return grade > y.grade;
    }
};
int main()
{
    std::vector<student> data;
    std::vector<student> result;
    int N, low, high;
    std::cin >> N;
    while (N--)
    {
        student s;
        std::cin >> s.name >> s.id >> s.grade;
        data.push_back(s);
    }
    std::cin >> low >> high;
    for (auto iter = data.begin(); iter != data.end(); iter++)
        if (iter->grade >= low && iter->grade <= high)
            result.push_back(*iter);
    std::sort(result.begin(), result.end());
    if (result.empty())
    {
        std::cout << "NONE" << std::endl;
        return 0;
    }
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << iter->name << " " << iter->id << std::endl;
    return 0;
}
