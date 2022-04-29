#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    int n = 0, q = 0;
    std::cin >> n >> q;
    std::vector<long long> pre_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> pre_sum[i];
        pre_sum[i] += pre_sum[i - 1];
    }
    while (q--) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        std::cout << pre_sum[r] - pre_sum[l - 1] << std::endl;
    }
    return 0;
}
