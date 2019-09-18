#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 999999

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N + 1, (std::vector<int>(N + 1, MAX)));
    while (M--)
    {
        int x, y, length;
        std::cin >> x >> y >> length;
        data[x][y] = data[y][x] = length;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (j == k)
                    data[j][k] = 0;
                else if (data[j][i] + data[i][k] < data[j][k])
                    data[j][k] = data[j][i] + data[i][k];
            }
        }
    }
    std::vector<int> max(N + 1);
    for (int i = 1; i <= N; i++)
        max[i] = *std::max_element(data[i].begin() + 1, data[i].end());
    if (MAX == *std::max_element(max.begin() + 1, max.end()))
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    auto min = std::min_element(max.begin() + 1, max.end());
    std::cout << std::distance(max.begin(), min) << " " << *min << std::endl;
    return 0;
}
