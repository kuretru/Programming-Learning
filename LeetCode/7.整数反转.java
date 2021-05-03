/*
 * @lc app=leetcode.cn id=7 lang=java
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        long result = x % 10;
        for (x /= 10; x != 0; x /= 10) {
            result = result * 10 + x % 10;
        }
        return (int)((result == (int)result) ? result : 0);
    }
}
// @lc code=end
