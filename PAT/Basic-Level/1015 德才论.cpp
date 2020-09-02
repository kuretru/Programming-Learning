#include <algorithm>
#include <iostream>
#include <vector>

struct person
{
    int id = 0;
    int virtue = 0;
    int talent = 0;
    int total = 0;
    int sort = 0;
    
    bool operator<(const person &y) const
    {
        if (sort != y.sort)
            return sort < y.sort;
        if (total != y.total)
            return total > y.total;
        if (virtue != y.virtue)
            return virtue > y.virtue;
        return id < y.id;
    }
};

int main()
{
    int N = 0, L = 0, H = 0;
    std::cin >> N >> L >> H;
    std::vector<person> result;
    while (N--)
    {
        person p;
        std::cin >> p.id >> p.virtue >> p.talent;
        p.total = p.virtue + p.talent;
        if (p.virtue >= L && p.talent >= L)
        {
            if (p.virtue >= H && p.talent >= H)
                p.sort = 0;
            else if (p.virtue >= H)
                p.sort = 1;
            else if (p.virtue >= p.talent)
                p.sort = 2;
            else
                p.sort = 3;
            result.push_back(p);
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++)
        printf("%08d %d %d\n", iter->id, iter->virtue, iter->talent);
    return 0;
}
