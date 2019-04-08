#include <algorithm>
#include <iostream>
#include <string>
struct student
{
    std::string name;
    int id, grade;
};
int C;
bool cmp(const student &x, const student &y)
{
    if (C == 2 && x.name != y.name)
        return x.name < y.name;
    if (C == 3 && x.grade != y.grade)
        return x.grade < y.grade;
    return x.id < y.id;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N >> C;
    student *data = new student[N];
    for (int i = 0; i < N; i++)
        std::cin >> data[i].id >> data[i].name >> data[i].grade;
    std::sort(data, data + N, cmp);
    for (int i = 0; i < N; i++)
        printf("%06d %s %d\n", data[i].id, data[i].name.c_str(), data[i].grade);
    return 0;
}
