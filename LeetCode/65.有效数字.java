/*
 * @lc app=leetcode.cn id=65 lang=java
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
    public boolean isNumber(String s) {
        char[] text = s.toCharArray();
        int start = 0;
        if (text[0] == '+' || text[0] == '-') {
            start++;
        }
        int dotCount = 0;
        int eCount = 0;
        int symbolCount = 0;
        int digitCount = 0;
        for (int i = start; i < text.length; i++) {
            if (text[i] == '.') {
                if (eCount > 0 || ++dotCount > 1) {
                    return false;
                }
            } else if (Character.toLowerCase(text[i]) == 'e') {
                if (digitCount == 0 || ++eCount > 1) {
                    return false;
                }
            } else if (text[i] == '+' || text[i] == '-') {
                if (Character.toLowerCase(text[i - 1]) != 'e' || ++symbolCount > 1) {
                    return false;
                }
            } else if (Character.isDigit(text[i])) {
                digitCount++;
            } else {
                return false;
            }
        }
        if (eCount == 1 && !Character.isDigit(text[text.length - 1])) {
            return false;
        }
        return digitCount > 0;
    }
}
// @lc code=end
