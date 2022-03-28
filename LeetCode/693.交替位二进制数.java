/*
 * @lc app=leetcode.cn id=693 lang=java
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
    public boolean hasAlternatingBits(int n) {
        boolean one = (n & 0x1) == 1;
        while (n > 0) {
            if (((n & 0x1) == 1) != one) {
                return false;
            }
            one = !one;
            n >>= 1;
        }
        return true;
    }
}
// @lc code=end
