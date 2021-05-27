/*
 * @lc app=leetcode.cn id=461 lang=java
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
    public int hammingDistance(int x, int y) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if ((x & 0x1) != (y & 0x1)) {
                result++;
            }
            x >>>= 1;
            y >>>= 1;
        }
        return result;
    }
}
// @lc code=end
