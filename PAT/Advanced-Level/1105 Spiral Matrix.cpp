#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    int N = 0, m = 0, n = 0;
    std::cin >> N;
    for (n = sqrt(N); n > 0; n--)
    {
        if (N / n * n == N)
        {
            m = N / n;
            break;
        }
    }
    std::vector<int> sequence(N);
    for (int i = 0; i < N; i++)
        std::cin >> sequence[i];
    std::sort(sequence.rbegin(), sequence.rend());
    std::vector<std::vector<int>> data(m, std::vector<int>(n));
    int x = 0, y = -1, step = 0;
    for (auto iter = sequence.begin(); iter != sequence.end();)
    {
        if (step == 0 && (y + 1 == n || data[x][y + 1]))
            step = 1;
        else if (step == 1 && (x + 1 == m || data[x + 1][y]))
            step = 2;
        else if (step == 2 && (y - 1 < 0 || data[x][y - 1]))
            step = 3;
        else if (step == 3 && (x - 1 < 0 || data[x - 1][y]))
            step = 0;
        x += direction[step][0];
        y += direction[step][1];
        data[x][y] = *(iter++);
    }
    for (auto row : data)
        for (auto iter = row.begin(); iter != row.end(); iter++)
            std::cout << *iter << (iter != row.end() - 1 ? " " : "\n");
    return 0;
}
