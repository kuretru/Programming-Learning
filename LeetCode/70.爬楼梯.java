/*
 * @lc app=leetcode.cn id=70 lang=java
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
    public int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        int last = 1, result = 1;
        for (int i = 1; i < n; i++) {
            int sum = last + result;
            last = result;
            result = sum;
        }
        return result;
    }
}
// @lc code=end
