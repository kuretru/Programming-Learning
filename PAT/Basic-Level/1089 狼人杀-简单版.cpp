// 固定两个撒谎者，暴力尝试的版本

#include <iostream>
#include <set>
#include <vector>

using std::set;

struct wolves
{
    int wolve1 = 0;
    int wolve2 = 0;
    wolves(std::set<int> wolves, int wolve)
    {
        wolves.insert(wolve);
        this->wolve1 = *wolves.begin();
        wolves.erase(wolves.begin());
        this->wolve2 = *wolves.begin();
    }
    bool operator<(const wolves &y) const
    {
        if (wolve1 != y.wolve1)
            return wolve1 < y.wolve1;
        return wolve2 < y.wolve2;
    }
};

void solve(std::set<wolves> &result, set<int> human, set<int> werewolves, int wolve1, int human2, int N)
{
    werewolves.insert(wolve1);
    human.insert(human2);
    if (werewolves.size() > 2)
        return;
    for (int i : werewolves)
        if (human.count(i))
            return;
    if (werewolves.size() == 1)
    {
        for (int i = 1; i <= N; i++)
            if (!human.count(i) && !werewolves.count(i))
                result.insert(wolves(werewolves, i));
        return;
    }
    result.insert(wolves(werewolves, wolve1));
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<int> data(N + 1);
    for (int i = 1; i <= N; i++)
        std::cin >> data[i];
    std::set<wolves> result;
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++) // 双重循环，遍历谎言家，i和j表示两个谎言家
        {
            set<int> human, werewolves;
            for (int k = 1; k <= N; k++)
            {
                int value = data[k];
                if (k == i || k == j) // 撒谎的取反
                    value = -value;
                if (value > 0)
                    human.insert(value);
                else if (value < 0)
                    werewolves.insert(-value); // 狼人是负数，取反
            }
            if (werewolves.size() > 2)
                continue;
            solve(result, human, werewolves, i, j, N);
            solve(result, human, werewolves, j, i, N);
        }
    }
    if (result.empty())
        std::cout << "No Solution" << std::endl;
    else
        std::cout << result.begin()->wolve1 << " " << result.begin()->wolve2 << std::endl;
    return 0;
}
