#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, M = 0;
    std::cin >> N >> M;
    vector<int> data(N + 1);
    for (int i = 1; i <= N; i++)
        std::cin >> data[i];
    std::sort(data.rbegin(), data.rbegin() + N);
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    vector<vector<bool>> used(N + 1, vector<bool>(M + 1, false));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (j >= data[i] && dp[i - 1][j - data[i]] + data[i] >= dp[i - 1][j])
            {
                dp[i][j] = dp[i - 1][j - data[i]] + data[i];
                used[i][j] = true;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[N][M] == M)
    {
        vector<int> result;
        for (int i = N, j = M; j > 0; i--)
        {
            while (!used[i][j])
                i--;
            j -= data[i];
            result.push_back(data[i]);
        }
        for (auto iter = result.begin(); iter != result.end(); iter++)
            std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    }
    else
        std::cout << "No Solution" << std::endl;
    return 0;
}
