#include <iostream>
#include <vector>

using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    int n = 0, m = 0, q = 0;
    std::cin >> n >> m >> q;
    vector<vector<long long>> pre_sum(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> pre_sum[i][j];
            pre_sum[i][j] += pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
        }
    }
    while (q--) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        long long result = pre_sum[x2][y2] - pre_sum[x1 - 1][y2] - pre_sum[x2][y1 - 1] + pre_sum[x1 - 1][y1 - 1];
        std::cout << result << std::endl;
    }
    return 0;
}
