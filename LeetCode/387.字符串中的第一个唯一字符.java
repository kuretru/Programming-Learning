/*
 * @lc app=leetcode.cn id=387 lang=java
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
    public int firstUniqChar(String s) {
        char[] chars = s.toCharArray();
        int[] counts = new int[255];
        for (char aChar : chars) {
            counts[aChar]++;
        }
        for (int i = 0; i < chars.length; i++) {
            if (counts[chars[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
}
// @lc code=end
