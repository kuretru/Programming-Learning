#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

struct school
{
    std::string name = "";
    int tws = 0;
    int ns = 0;
    std::map<char, int> scores;
    bool operator<(const school &y) const
    {
        if (tws != y.tws)
            return tws > y.tws;
        if (ns != y.ns)
            return ns < y.ns;
        return name < y.name;
    }
};

int main()
{
    std::map<std::string, school> data;
    int N = 0;
    std::cin >> N;
    while (N--)
    {
        std::string id = "", name = "";
        int score = 0;
        std::cin >> id >> score >> name;
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        data[name].name = name;
        data[name].scores[id[0]] += score;
        data[name].ns++;
    }
    std::set<school> result;
    for (auto pair : data)
    {
        school s = pair.second;
        s.tws = s.scores['T'] * 1.5 + s.scores['A'] + s.scores['B'] / 1.5;
        result.insert(s);
    }
    std::cout << result.size() << std::endl;
    int rank = 1, lastTWS = -1, lastRank = -1;
    for (auto iter = result.begin(); iter != result.end(); iter++, rank++)
    {
        std::cout << (iter->tws == lastTWS ? lastRank : rank);
        std::cout << " " << iter->name << " " << iter->tws << " " << iter->ns << std::endl;
        if (iter->tws != lastTWS)
            lastRank = rank;
        lastTWS = iter->tws;
    }
    return 0;
}
