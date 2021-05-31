/*
 * @lc app=leetcode.cn id=342 lang=java
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
    public boolean isPowerOfFour(int n) {
        int ones = 0;
        int zeros = 0;
        while (n > 0) {
            if ((n & 0x1) == 1) {
                ones++;
            } else {
                zeros++;
            }
            n >>>= 1;
        }
        return ones == 1 && zeros % 2 == 0;
    }
}
// @lc code=end
