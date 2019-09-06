#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int N = 0, K = 0;
    std::cin >> N;
    std::vector<std::unordered_set<int>> data(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int count = 0, key = 0;
        std::cin >> count;
        while (count--)
        {
            std::cin >> key;
            data[i].insert(key);
        }
    }
    std::cin >> K;
    while (K--)
    {
        int x = 0, y = 0, count = 0;
        std::cin >> x >> y;
        for (int i : data[x])
            if (!data[y].count(i))
                count++;
        printf("%.1lf%%\n", (data[x].size() - count) * 100.0 / (data[y].size() + count));
    }
    return 0;
}
