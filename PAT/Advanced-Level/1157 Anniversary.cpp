#include <iostream>
#include <set>
#include <string>

struct visitor
{
    std::string id = "";
    int birth = 0;
    bool operator<(const visitor &y) const
    {
        if (birth != y.birth)
            return birth < y.birth;
        return id < y.id;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, M = 0;
    std::cin >> N;
    std::set<visitor> alumni, guest, comesAlumni;
    for (int i = 0; i < N; i++)
    {
        visitor v;
        std::cin >> v.id;
        v.birth = std::stoi(v.id.substr(6, 8));
        alumni.insert(v);
    }
    std::cin >> M;
    while (M--)
    {
        visitor v;
        std::cin >> v.id;
        v.birth = std::stoi(v.id.substr(6, 8));
        guest.insert(v);
        if (alumni.count(v))
            comesAlumni.insert(v);
    }
    std::cout << comesAlumni.size() << std::endl;
    if (comesAlumni.empty())
        std::cout << guest.begin()->id << std::endl;
    else
        std::cout << comesAlumni.begin()->id << std::endl;
    return 0;
}
