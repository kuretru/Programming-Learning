/*
 * @lc app=leetcode.cn id=191 lang=java
 *
 * [191] 位1的个数
 */

// @lc code=start
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int result = 0;
        for (; n != 0; n >>>= 1) {
            if ((n & 1) == 1) {
                result++;
            }
        }
        return result;
    }
}
// @lc code=end
