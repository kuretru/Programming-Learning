/*
 * @lc app=leetcode.cn id=806 lang=java
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
    public int[] numberOfLines(int[] widths, String s) {
        int[] result = new int[]{1, 0};
        char[] data = s.toCharArray();
        for (char c : data) {
            if (result[1] + widths[c - 'a'] > 100) {
                result[0]++;
                result[1] = 0;
            }
            result[1] += widths[c - 'a'];
        }
        return result;
    }
}
// @lc code=end
