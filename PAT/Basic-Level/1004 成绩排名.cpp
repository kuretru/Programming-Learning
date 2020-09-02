#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct student
{
    std::string name = "";
    std::string number = "";
    int score = 0;

    int operator<(const student &y)
    {
        return this->score < y.score;
    }
};

int main()
{
    int count = 0;
    std::cin >> count;
    std::vector<student> data(count);
    for (int i = 0; i < count; i++)
        std::cin >> data[i].name >> data[i].number >> data[i].score;
    std::sort(data.begin(), data.end());
    std::cout << data.back().name << " " << data.back().number << std::endl;
    std::cout << data.front().name << " " << data.front().number << std::endl;
    return 0;
}
