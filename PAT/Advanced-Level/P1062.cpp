#include <algorithm>
#include <iostream>
#include <vector>
struct person
{
    int id, virtue, talent, total, sort;
    bool operator<(const person &y) const
    {
        if (sort == y.sort)
        {
            if (total == y.total)
            {
                if (virtue == y.virtue)
                    return id < y.id;
                return virtue > y.virtue;
            }
            return total > y.total;
        }
        return sort < y.sort;
    }
};
int main()
{
    int N, L, H;
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
