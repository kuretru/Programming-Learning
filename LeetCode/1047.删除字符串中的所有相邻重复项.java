/*
 * @lc app=leetcode.cn id=1047 lang=java
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
    public String removeDuplicates(String S) {
        char[] stack = S.toCharArray();
        int top = -1;
        for (char c : stack) {
            if (top != -1 && stack[top] == c) {
                top--;
                continue;
            }
            stack[++top] = c;
        }
        return new String(stack, 0, top + 1);
    }
}
// @lc code=end
