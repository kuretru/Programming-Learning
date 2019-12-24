/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        String result = "";
        exit:
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].length() <= i) {
                    break exit;
                }
                if (strs[0].charAt(i) != strs[j].charAt(i)) {
                    break exit;
                }
            }
            result += strs[0].charAt(i);
        }
        return result;
    }
}
// @lc code=end
