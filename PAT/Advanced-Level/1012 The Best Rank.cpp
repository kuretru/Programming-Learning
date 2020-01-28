#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::string symbol[] = {"A", "C", "M", "E"};

struct student
{
    int id = 0;
    int grades[4];
    int ranks[4];
};

int order;

bool cmp(const student *x, const student *y)
{
    return x->grades[order] > y->grades[order];
}

int main()
{
    std::map<int, student *> data;
    std::vector<student *> temp;
    int N = 0, M = 0, key = 0;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        student *record = new student();
        std::cin >> record->id >> record->grades[1] >> record->grades[2] >> record->grades[3];
        record->grades[0] = (int)((record->grades[1] + record->grades[2] + record->grades[3]) / 3 + 0.5);
        data[record->id] = record;
        temp.push_back(record);
    }
    for (int i = 0; i < 4; i++)
    {
        order = i;
        sort(temp.begin(), temp.end(), cmp);
        temp[0]->ranks[i] = 1;
        for (int j = 1, rank = 2; j < N; j++, rank++)
        {
            if (temp[j]->grades[i] == temp[j - 1]->grades[i])
                temp[j]->ranks[i] = temp[j - 1]->ranks[i];
            else
                temp[j]->ranks[i] = rank;
        }
    }
    while (M--)
    {
        std::cin >> key;
        if (data.find(key) == data.end())
        {
            std::cout << "N/A" << std::endl;
            continue;
        }
        int min = 0;
        for (int i = 1; i < 4; i++)
            if (data[key]->ranks[i] < data[key]->ranks[min])
                min = i;
        std::cout << data[key]->ranks[min] << " " << symbol[min] << std::endl;
    }
    return 0;
}
