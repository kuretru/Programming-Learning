/*
 * @lc app=leetcode.cn id=9 lang=java
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        String number = String.valueOf(x);
        for (int i = 0, j = number.length() - 1; i < j; i++, j--) {
            if (number.charAt(i) != number.charAt(j)) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
