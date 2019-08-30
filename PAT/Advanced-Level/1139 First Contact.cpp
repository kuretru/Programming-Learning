#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct person
{
    std::string id = "";
    bool girl = false;
    person(std::string id)
    {
        this->id = id;
        this->girl = id[0] == '-';
    }
    bool operator<(const person &y) const
    {
        return id < y.id;
    }
};

struct bridge
{
    int x = 0;
    int y = 0;
    bridge(std::string x, std::string y)
    {
        this->x = std::abs(std::stoi(x));
        this->y = std::abs(std::stoi(y));
    }
};

int main()
{
    std::map<std::string, std::set<person>> data;
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M;
    while (M--)
    {
        std::string x = "", y = "";
        std::cin >> x >> y;
        data[x].insert(person(y));
        data[y].insert(person(x));
    }
    std::cin >> K;
    while (K--)
    {
        std::set<person> xFriends, yFriends;
        std::string x = "", y = "";
        std::cin >> x >> y;
        person xPerson(x), yPerson(y);
        for (person p : data[x])
            if (xPerson.girl == p.girl && p.id != yPerson.id)
                xFriends.insert(p);
        for (person p : data[y])
            if (yPerson.girl == p.girl && p.id != xPerson.id)
                yFriends.insert(p);

        std::vector<bridge> result;
        for (person i : xFriends)
            for (person j : yFriends)
                if (data[i.id].count(j))
                    result.push_back(bridge(i.id, j.id));
        std::cout << result.size() << std::endl;
        for (bridge b : result)
            printf("%04d %04d\n", b.x, b.y);
    }
    return 0;
}
