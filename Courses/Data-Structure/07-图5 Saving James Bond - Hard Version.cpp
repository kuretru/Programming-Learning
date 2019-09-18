#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const float ISLAND = 7.5;

struct crocodile
{
    int x;
    int y;
    int distance;
    bool operator<(const crocodile &c) const
    {
        return distance < c.distance;
    }
};

struct node
{
    int vertex;
    std::vector<int> path;
};

int N, D;
std::vector<crocodile> data;

bool canJump(crocodile xPoint, crocodile yPoint)
{
    int x = abs(xPoint.x - yPoint.x);
    int y = abs(xPoint.y - yPoint.y);
    return x * x + y * y <= D * D;
}

bool isSave(crocodile xPoint)
{
    return 50 - abs(xPoint.x) <= D || 50 - abs(xPoint.y) <= D;
}

std::vector<crocodile> BFS(int start)
{
    std::vector<bool> visited(data.size(), false);
    std::queue<node> queue;
    node n;
    n.vertex = start;
    queue.push(n);
    while (!queue.empty())
    {
        n = queue.front();
        if (isSave(data[n.vertex]))
            break;
        queue.pop();
        if (visited[n.vertex])
            continue;
        visited[n.vertex] = true;
        n.path.push_back(n.vertex);
        for (int i = 0; i < data.size(); i++)
        {
            if (!visited[i] && canJump(data[n.vertex], data[i]))
            {
                node nn = n;
                nn.vertex = i;
                queue.push(nn);
            }
        }
    }
    std::vector<crocodile> result;
    if (!queue.empty())
    {
        node n = queue.front();
        n.path.push_back(n.vertex);
        for (auto iter = n.path.begin(); iter != n.path.end(); iter++)
            result.push_back(data[*iter]);
    }
    return result;
}

int main()
{
    std::cin >> N >> D;
    while (N--)
    {
        crocodile c;
        std::cin >> c.x >> c.y;
        if (abs(c.x) < ISLAND && abs(c.y) < ISLAND)
            continue;
        if (abs(c.x) == 50 || abs(c.y) == 50)
            continue;
        c.distance = c.x * c.x + c.y * c.y;
        data.push_back(c);
    }
    std::sort(data.begin(), data.end());

    if (D + ISLAND >= 50)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    std::vector<crocodile> result;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].distance > (D + ISLAND) * (D + ISLAND))
            continue;
        std::vector<crocodile> min = BFS(i);
        if (min.size() == 0)
            continue;
        if (result.empty() || min.size() < result.size())
            result = min;
    }
    std::cout << (result.empty() ? 0 : result.size() + 1) << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << iter->x << " " << iter->y << std::endl;
    return 0;
}
