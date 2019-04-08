#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
struct school
{
    std::string name;
    int top, advanced, basic, total, count;
    bool operator<(const school &y) const
    {
        if (total == y.total)
        {
            if (count == y.count)
                return name < y.name;
            return count < y.count;
        }
        return total > y.total;
    }
};
int main()
{
    int count;
    std::cin >> count;
    std::map<std::string, school> map;
    while (count--)
    {
        std::string id, school;
        int grade;
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
