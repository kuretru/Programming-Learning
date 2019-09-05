#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N + 1);
    while (M--)
    {
        int id = 0, k = 0;
        std::cin >> id >> k;
        data[id].resize(k);
        for (int i = 0; i < k; i++)
            std::cin >> data[id][i];
    }
    int max = 0, level = 0;
    std::queue<int> queue;
    queue.push(1);
    for (int i = 1; !queue.empty(); i++)
    {
        if (queue.size() > max)
        {
            max = queue.size();
            level = i;
        }
        std::queue<int> generation;
        while (!queue.empty())
        {
            int id = queue.front();
            queue.pop();
            for (int j : data[id])
                generation.push(j);
        }
        queue = generation;
    }
    std::cout << max << " " << level << std::endl;
    return 0;
}
