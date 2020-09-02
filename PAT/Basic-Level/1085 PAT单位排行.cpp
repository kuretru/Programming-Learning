#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

struct school
{
    std::string name = "";
    int top = 0;
    int advanced = 0;
    int basic = 0;
    int total = 0;
    int count = 0;
    bool operator<(const school &y) const
    {
        if (total != y.total)
            return total > y.total;
        if (count != y.count)
            return count < y.count;
        return name < y.name;
    }
};

int main()
{
    int count = 0;
    std::cin >> count;
    std::map<std::string, school> map;
    while (count--)
    {
        std::string id = "", school = "";
        int grade = 0;
        std::cin >> id >> grade >> school;
        std::transform(school.begin(), school.end(), school.begin(), ::tolower);
        map[school].name = school;
        map[school].count++;
        if (id[0] == 'T')
            map[school].top += grade;
        else if (id[0] == 'A')
            map[school].advanced += grade;
        else
            map[school].basic += grade;
    }
    std::set<school> list;
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        school record = iter->second;
        record.total = (int)(1.5 * record.top + record.advanced + record.basic / 1.5);
        list.insert(record);
    }
    int rank = 1, lastGrade = -1, lastRank = -1;
    std::cout << list.size() << std::endl;
    for (auto iter = list.begin(); iter != list.end(); iter++, rank++)
    {
        if (iter->total != lastGrade)
        {
            std::cout << rank;
            lastRank = rank;
        }
        else
        {
            std::cout << lastRank;
        }
        std::cout << " " << iter->name << " " << iter->total << " " << iter->count << std::endl;
        lastGrade = iter->total;
    }
    return 0;
}
