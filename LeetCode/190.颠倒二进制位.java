/*
 * @lc app=leetcode.cn id=190 lang=java
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (i != 0) {
                n >>>= 1;
                result <<= 1;
            }
            result |= (n & 0x1);
        }
        return result;
    }
}
// @lc code=end
