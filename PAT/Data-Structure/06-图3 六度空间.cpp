// 此题不能使用DFS，有环路情况时，若从长路先走，会导致短路失效

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

struct node
{
    int vertex;
    int level;
    node(int vertex, int level)
    {
        this->vertex = vertex;
        this->level = level;
    }
};

std::vector<std::vector<int>> data;

int BFS(int vertex)
{
    std::vector<bool> visited(data.size(), false);
    visited[vertex] = true;
    std::queue<node> queue;
    queue.push(node(vertex, 0));
    int vertices = 1;
    while (!queue.empty())
    {
        node n = queue.front();
        queue.pop();
        for (int i = 1; i <= data.size(); i++)
        {
            if (data[n.vertex][i] != 0 && !visited[i] && n.level < 6)
            {
                queue.push(node(i, n.level + 1));
                visited[i] = true;
                vertices++;
            }
        }
    }
    return vertices;
}

int main()
{
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    data.resize(N + 1, std::vector<int>(N + 1, 0));
    while (M--)
    {
        scanf("%d %d", &x, &y);
        data[x][y] = data[y][x] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        int vertices = BFS(i);
        printf("%d: %.2f%%\n", i, vertices * 100.0 / N);
    }
    return 0;
}
