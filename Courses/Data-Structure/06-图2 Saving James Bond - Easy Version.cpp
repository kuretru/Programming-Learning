#include <iostream>
#include <vector>

const float ISLAND = 7.5;

struct crocodile
{
    int x;
    int y;
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

bool DFS(std::vector<bool> &visited, int vertex)
{
    if (visited[vertex])
        return false;
    visited[vertex] = true;
    if (isSave(data[vertex]))
        return true;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && canJump(data[vertex], data[i]))
        {
            if (DFS(visited, i))
                return true;
        }
    }
    return false;
}

int main()
{
    std::cin >> N >> D;
    data.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i].x >> data[i].y;
    bool save = false;
    for (int i = 0; i < N; i++)
    {
        int distance = data[i].x * data[i].x + data[i].y * data[i].y;
        if (distance > (D + ISLAND) * (D + ISLAND))
            continue;
        std::vector<bool> visited(N, false);
        if (DFS(visited, i))
        {
            save = true;
            break;
        }
    }
    std::cout << (save ? "Yes" : "No") << std::endl;
    return 0;
}
