#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, M = 0, L = 0, tmp = 0;
    std::cin >> N >> M;
    std::vector<int> map(N + 1);
    std::vector<bool> favorites(N + 1, false);
    for (int i = 1; i <= M; i++)
    {
        std::cin >> tmp;
        map[tmp] = i;
        favorites[tmp] = true;
    }
    std::cin >> L;
    std::vector<int> data(L), dp(L);
    for (int i = 0; i < L; i++)
        std::cin >> data[i];
    for (int i = 0; i < L; i++)
    {
        if (!favorites[data[i]])
            continue;
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (!favorites[data[j]])
                continue;
            if (map[data[j]] <= map[data[i]])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }
    int result = *std::max_element(dp.begin(), dp.end());
    std::cout << result << std::endl;
    return 0;
}
