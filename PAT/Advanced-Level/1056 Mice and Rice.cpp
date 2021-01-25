#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct mice
{
    int weight = 0;
    int order = 0;
    int rank = 0;
};

int find_fattest(std::vector<mice> &data, std::vector<int> &match, int failedRank, int start, int end)
{
    int max = start;
    for (int i = start + 1; i < end; i++)
        if (data[match[i]].weight > data[match[max]].weight)
            max = i;
    for (int i = start; i < end; i++)
        if (i != max)
            data[match[i]].rank = failedRank;
    return match[max];
}

int main()
{
    int Np = 0, Ng = 0;
    std::cin >> Np >> Ng;
    std::vector<mice> data(Np);
    for (int i = 0; i < Np; i++)
        std::cin >> data[i].weight;
    for (int i = 0; i < Np; i++)
        std::cin >> data[i].order;

    std::vector<int> match(Np);
    for (int i = 0; i < Np; i++)
        match[i] = data[i].order;
    while (match.size() > 1)
    {
        std::vector<int> next;
        int failedRank = (int)((match.size() + Ng - 1) * 1.0 / Ng) + 1;
        for (int i = 0; i < match.size(); i += Ng)
        {
            int end = std::min((int)match.size(), i + Ng);
            int fattest = find_fattest(data, match, failedRank, i, end);
            next.push_back(fattest);
        }
        match = next;
    }
    data[match[0]].rank = 1;

    for (int i = 0; i < Np; i++)
        std::cout << data[i].rank << (i != Np - 1 ? " " : "\n");
    return 0;
}
