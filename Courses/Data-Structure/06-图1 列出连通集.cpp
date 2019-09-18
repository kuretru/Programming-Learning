#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> data;

void DFS(std::vector<bool> &visited, std::vector<int> &sequence, int vertex)
{
    if (visited[vertex])
        return;
    visited[vertex] = true;
    sequence.push_back(vertex);
    for (int i = 0; i < data.size(); i++)
        if (data[vertex][i] != 0)
            DFS(visited, sequence, i);
}

void BFS(std::vector<bool> &visited, std::vector<int> &sequence, int vertex)
{
    std::queue<int> queue;
    queue.push(vertex);
    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop();
        if (!visited[v])
        {
            visited[v] = true;
            sequence.push_back(v);
            for (int i = 0; i < data.size(); i++)
                if (data[v][i] != 0)
                    queue.push(i);
        }
    }
}

void computer(void search(std::vector<bool> &visited, std::vector<int> &sequence, int vertex))
{
    std::vector<bool> visited(data.size(), false);
    for (int i = 0; i < data.size(); i++)
    {
        if (!visited[i])
        {
            std::vector<int> sequence;
            search(visited, sequence, i);
            std::cout << "{ ";
            for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
                std::cout << *iter << " ";
            std::cout << "}" << std::endl;
        }
    }
}

int main()
{
    int N, E, x, y;
    std::cin >> N >> E;
    data.resize(N, std::vector<int>(N, 0));
    while (E--)
    {
        std::cin >> x >> y;
        data[x][y] = data[y][x] = 1;
    }
    computer(DFS);
    computer(BFS);
    return 0;
}
