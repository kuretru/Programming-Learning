/*
 * @lc app=leetcode.cn id=917 lang=java
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] data = s.toCharArray();
        for (int i = 0, j = data.length - 1; i < j; i++, j--) {
            while (i < j && !Character.isLetter(data[i])) {
                i++;
            }
            while (i < j && !Character.isLetter(data[j])) {
                j--;
            }
            if (i < j) {
                char tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
        return new String(data);
    }
}
// @lc code=end
