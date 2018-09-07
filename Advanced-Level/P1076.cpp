#include <iostream>
#include <queue>
#include <set>
#include <vector>
struct position
{
    int index;
    int level;
    position(int index, int level)
    {
        this->index = index;
        this->level = level;
    };
};
int main()
{
    int N, L, count, key;
    std::cin >> N >> L;
    std::vector<std::vector<int>> data(N + 1);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> count;
        while (count--)
        {
            std::cin >> key;
            data[key].push_back(i);
        }
    }
    std::cin >> count;
    while (count--)
    {
        std::cin >> key;
        std::set<int> result;
        std::vector<bool> flags(N + 1, false);
        std::queue<position> bfs;
        bfs.push(position(key, 0));
        flags[key] = true;
        while (!bfs.empty())
        {
            position p = bfs.front();
            bfs.pop();
            result.insert(p.index);
            if (p.level < L)
            {
                for (auto iter = data[p.index].begin(); iter != data[p.index].end(); iter++)
                {
                    if (!flags[*iter])
                    {
                        flags[*iter] = true;
                        bfs.push(position(*iter, p.level + 1));
                    }
                }
            }
        }
        std::cout << result.size() - 1 << std::endl;
    }
    return 0;
}
