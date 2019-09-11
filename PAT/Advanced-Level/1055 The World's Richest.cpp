#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct person
{
    std::string name = "";
    int age = 0;
    int worth = 0;
    bool operator<(const person &y) const
    {
        if (worth != y.worth)
            return worth > y.worth;
        if (age != y.age)
            return age < y.age;
        return name < y.name;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, K = 0;
    std::cin >> N >> K;
    std::vector<std::vector<person>> data(201);
    while (N--)
    {
        person p;
        std::cin >> p.name >> p.age >> p.worth;
        data[p.age].push_back(p);
    }
    for (int i = 1; i <= 200; i++)
        std::sort(data[i].begin(), data[i].end());
    for (int i = 1; i <= K; i++)
    {
        std::cout << "Case #" << i << ":" << std::endl;
        int M = 0, Amin = 0, Amax = 0;
        std::cin >> M >> Amin >> Amax;
        // 多路归并不排序直接输出
        std::vector<person> result;
        std::vector<int> index(201, 0);
        while (M--)
        {
            int max = -1;
            for (int j = Amin; j <= Amax; j++)
                if (index[j] < data[j].size() && (max == -1 || data[j][index[j]] < data[max][index[max]]))
                    max = j;
            if (max == -1)
                break;
            result.push_back(data[max][index[max]++]);
        }
        if (result.empty())
            std::cout << "None" << std::endl;
        for (person p : result)
            std::cout << p.name << " " << p.age << " " << p.worth << std::endl;
    }
    return 0;
}
