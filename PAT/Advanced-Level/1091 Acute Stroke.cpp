#include <iostream>
#include <queue>
#include <vector>

using std::vector;

const int DIRECTION[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int M = 0, N = 0, L = 0, T = 0;

struct point
{
    int x = 0;
    int y = 0;
    int z = 0;
    point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    bool is_legal()
    {
        if (x < 0 || y < 0 || z < 0)
            return false;
        if (x >= L || y >= M || z >= N)
            return false;
        return true;
    }
};

int bfs(vector<vector<vector<int>>> &data, vector<vector<vector<bool>>> &visited, point p)
{
    int result = 0;
    std::queue<point> queue;
    queue.push(p);
    while (!queue.empty())
    {
        p = queue.front();
        queue.pop();
        if (!p.is_legal() || visited[p.x][p.y][p.z])
            continue;
        visited[p.x][p.y][p.z] = true;
        if (data[p.x][p.y][p.z])
        {
            result++;
            for (int i = 0; i < 6; i++)
                queue.push(point(p.x + DIRECTION[i][0], p.y + DIRECTION[i][1], p.z + DIRECTION[i][2]));
        }
    }
    return result >= T ? result : 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> M >> N >> L >> T;
    vector<vector<vector<int>>> data(L, vector<vector<int>>(M, vector<int>(N, 0)));
    vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(M, vector<bool>(N, false)));
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                std::cin >> data[i][j][k];
    int result = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                if (!visited[i][j][k] && data[i][j][k])
                    result += bfs(data, visited, point(i, j, k));
    std::cout << result << std::endl;
    return 0;
}
