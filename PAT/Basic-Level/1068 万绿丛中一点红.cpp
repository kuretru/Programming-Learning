#include <iostream>
#include <map>
#include <vector>

using std::vector;

const int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool judge(vector<vector<int>> &data, int x, int y, int TOL)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int target = data[x + direction[i][0]][y + direction[i][1]];
        if (target == -1 || abs(data[x][y] - target) > TOL)
            count++;
    }
    return count == 8;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int M = 0, N = 0, TOL = 0;
    int x = 0, y = 0, count = 0;
    std::cin >> M >> N >> TOL;
    std::map<int, int> counts;
    vector<vector<int>> data(N + 2, vector<int>(M + 2, -1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            std::cin >> data[i][j];
            counts[data[i][j]]++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (counts[data[i][j]] == 1 && judge(data, i, j, TOL))
            {
                x = i;
                y = j;
                count++;
            }
        }
    }
    if (count == 0)
        std::cout << "Not Exist" << std::endl;
    else if (count > 1)
        std::cout << "Not Unique" << std::endl;
    else
        printf("(%d, %d): %d\n", y, x, data[x][y]);
    return 0;
}
