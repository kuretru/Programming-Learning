#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
struct student
{
    std::string name;
    int score[3] = {-1, -1, -1};
    int sum;
    bool operator<(const student t) const
    {
        if (this->sum == t.sum)
            return this->name < t.name;
        return this->sum > t.sum;
    }
};
int main()
{
    std::map<std::string, student> data;
    std::vector<student> list;
    std::string name;
    int count[3];
    std::cin >> count[0] >> count[1] >> count[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            std::cin >> name;
            data[name].name = name;
            std::cin >> data[name].score[i];
        }
    }
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        if (iter->second.score[0] < 200)
            iter->second.sum = 0;
        else
        {
            if (iter->second.score[1] > iter->second.score[2])
                iter->second.sum = iter->second.score[1] * 0.4 + iter->second.score[2] * 0.6 + 0.5;
            else
                iter->second.sum = iter->second.score[2];
        }
        if (iter->second.sum >= 60)
            list.push_back(iter->second);
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list[i].name << " ";
        for (int j = 0; j < 3; j++)
            printf("%d ", list[i].score[j]);
        std::cout << list[i].sum << std::endl;
    }
    return 0;
}
