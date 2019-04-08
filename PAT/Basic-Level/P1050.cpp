#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
int main()
{
    std::ios::sync_with_stdio(false);
    const int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int N, tmp, m, n, x = 0, y = 0;
    std::vector<int> raw;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        raw.push_back(tmp);
    }
    sort(raw.rbegin(), raw.rend());
    for (n = sqrt(N); n > 1; n--)
        if (N % n == 0)
            break;
    m = N / n;
    std::vector<std::vector<int>> data(m, std::vector<int>(n, 0));
    for (int i = 0, j = 0; j < raw.size(); i = (i + 1) % 4)
    {
        while (j < raw.size())
        {
            if (data[x][y] == 0)
                data[x][y] = raw[j++];
            x += offset[i][0];
            y += offset[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n || data[x][y] != 0)
            {
                x -= offset[i][0];
                y -= offset[i][1];
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", data[i][j], j < n - 1 ? ' ' : '\n');
    return 0;
}
