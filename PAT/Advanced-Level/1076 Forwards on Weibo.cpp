#include <iostream>
#include <queue>
#include <set>
#include <vector>

struct position
{
    int index = 0;
    int level = 0;
    position(int index, int level)
    {
        this->index = index;
        this->level = level;
    };
};

int main()
{
    int N = 0, L = 0, K = 0;
    std::cin >> N >> L;
    std::vector<std::vector<int>> data(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int count = 0, key = 0;
        std::cin >> count;
        while (count--)
        {
            std::cin >> key;
            data[key].push_back(i);
        }
    }
    std::cin >> K;
    while (K--)
    {
        int key = 0;
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
