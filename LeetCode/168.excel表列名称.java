/*
 * @lc app=leetcode.cn id=168 lang=java
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder result = new StringBuilder();
        for (; columnNumber-- > 0; columnNumber /= 26) {
            result.append((char)(columnNumber % 26 + 'A'));
        }
        return result.reverse().toString();
    }
}
// @lc code=end
