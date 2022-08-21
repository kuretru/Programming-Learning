#include <algorithm>
#include <vector>

class Solution {
  public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        m %= n;
        std::reverse(a.begin(), a.end());
        std::reverse(a.begin(), a.begin() + m);
        std::reverse(a.begin() + m, a.end());
        return a;
    }
};
