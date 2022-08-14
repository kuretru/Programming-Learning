#include <vector>

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& num) {
        std::sort(num.begin(), num.end());
        vector<vector<int>> result;
        int length = num.size();
        for (int i = 0; i < length; i++) {
            for (int j = i + 1, k = length - 1; j < k;) {
                int sum = num[i] + num[j] + num[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.push_back({num[i], num[j], num[k]});
                    while (j < k && num[j] == num[j + 1]) {
                        j++;
                    }
                    while (j < k && num[k - 1] == num[k]) {
                        k--;
                    }
                    j++;
                    k--;
                }
            }
            while (i + 1 < length && num[i] == num[i + 1]) {
                i++;
            }
        }
        return result;
    }
};
