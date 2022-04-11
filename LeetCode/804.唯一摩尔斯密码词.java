/*
 * @lc app=leetcode.cn id=804 lang=java
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution {
    private static final String[] ENCODE_TABLE = new String[]{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    public int uniqueMorseRepresentations(String[] words) {
        Set<String> result = new HashSet<>(16);
        for (String word : words) {
            StringBuilder stringBuilder = new StringBuilder();
            for (char c : word.toCharArray()) {
                stringBuilder.append(ENCODE_TABLE[c - 'a']);
            }
            result.add(stringBuilder.toString());
        }
        return result.size();
    }
}
// @lc code=end
