/*
 * @lc app=leetcode.cn id=744 lang=java
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int length = letters.length;
        char result = letters[0];
        for (char letter : letters) {
            if (letter > target) {
                result = letter;
                break;
            }
        }
        return result;
    }
}
// @lc code=end
