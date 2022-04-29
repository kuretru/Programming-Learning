#include <iostream>
#include <string>
#include <vector>

using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    int n = 0;
    std::string text = "";
    std::cin >> n >> text;
    vector<vector<int>> pre_sum(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++) {
        pre_sum[i] = pre_sum[i - 1];
        pre_sum[i][text[i - 1] - 'a'] ++;
    }
    long long result = 0;
    for (int i = n - 2; i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (text[i - 1] - 'a' == j) {
                continue;
            }
            int count = pre_sum[n][j] - pre_sum[i][j];
            result += ((count - 1) * count) >> 1;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
