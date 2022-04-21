/*
 * @lc app=leetcode.cn id=824 lang=java
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
    public String toGoatLatin(String sentence) {
        String[] words = sentence.split(" ");
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (result.length() > 0) {
                result.append(' ');
            }
            char[] chars = words[i].toCharArray();
            boolean isAeiou = AEIOU[chars[0]];
            for (int j = isAeiou ? 0 : 1; j < chars.length; j++) {
                result.append(chars[j]);
            }
            if (!isAeiou) {
                result.append(chars[0]);
            }
            result.append("ma");
            for (int j = 0; j <= i; j++) {
                result.append('a');
            }
        }
        return result.toString();
    }
}
// @lc code=end
