/*
 * @lc app=leetcode.cn id=942 lang=java
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
    public int[] diStringMatch(String s) {
        char[] data = s.toCharArray();
        int[] result = new int[data.length + 1];
        int left = 0, right = data.length;
        for (int i = 0; i < data.length; i++) {
            result[i] = data[i] == 'I' ? left++ : right--;
        }
        result[data.length] = left;
        return result;
    }
}
// @lc code=end
