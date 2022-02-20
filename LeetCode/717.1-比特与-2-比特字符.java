/*
 * @lc app=leetcode.cn id=717 lang=java
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        for (int i = 0; i < bits.length; i++) {
            if (bits[i] == 0) {
                continue;
            } else if (i + 2 >= bits.length) {
                return false;
            }
            i++;
        }
        return true;
    }
}
// @lc code=end
