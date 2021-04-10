/*
 * @lc app=leetcode.cn id=263 lang=java
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
    public boolean isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        for (int i = 2; n > 1; i++) {
            if (i > 5) {
                return false;
            }
            while (n % i == 0) {
                n /= i;
            }
        }
        return true;
    }
}
// @lc code=end
