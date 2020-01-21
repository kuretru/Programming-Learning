#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<int> data[100];
    int N = 0, M = 0;
    std::cin >> N >> M;
    while (M-- > 0)
    {
        int id = 0, K = 0, child = 0;
        std::cin >> id >> K;
        while (K--)
        {
            std::cin >> child;
            data[id].push_back(child);
        }
    }
    std::queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int back = q.back(), count = 0;
        while (true)
        {
            int id = q.front();
            q.pop();
            if (data[id].empty())
                count++;
            for (auto iter = data[id].begin(); iter != data[id].end(); iter++)
                q.push(*iter);
            if (id == back)
                break;
        }
        if (q.empty())
            std::cout << count << std::endl;
        else
            std::cout << count << " ";
    }
    return 0;
}
