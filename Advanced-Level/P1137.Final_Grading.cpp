#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
struct student
{
    std::string id;
    int programming = -1, mid = -1, finall = -1, g;
    bool operator<(const student &y) const
    {
        if (g == y.g)
            return id < y.id;
        return g > y.g;
    }
};
int main()
{
    int P, M, N, value;
    std::map<std::string, student> data;
    std::string key;
    std::cin >> P >> M >> N;
    while (P--)
    {
        std::cin >> key >> value;
        data[key].programming = value;
    }
    while (M--)
    {
        std::cin >> key >> value;
        data[key].mid = value;
    }
    while (N--)
    {
        std::cin >> key >> value;
        data[key].finall = value;
    }
    std::vector<student> result;
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        student s = iter->second;
        s.id = iter->first;
        if (s.mid > s.finall)
            s.g = s.mid * 0.4 + s.finall * 0.6 + 0.5;
        else
            s.g = s.finall;
        if (s.programming >= 200 && s.g >= 60)
            result.push_back(s);
    }
    std::sort(result.begin(), result.end());
    for (auto iter = result.begin(); iter != result.end(); iter++)
    {
        std::cout << iter->id << " " << iter->programming << " " << iter->mid;
        std::cout << " " << iter->finall << " " << iter->g << std::endl;
    }
    return 0;
}
