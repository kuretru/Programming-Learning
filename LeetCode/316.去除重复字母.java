/*
 * @lc app=leetcode.cn id=316 lang=java
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
    public String removeDuplicateLetters(String s) {
        char[] chars = s.toCharArray();
        char[] stack = new char[26];
        int top = 0;
        int[] counts = new int[255];
        boolean[] visited = new boolean[255];
        for (char c : chars) {
            counts[c]++;
        }

        for (char c : chars) {
            counts[c]--;
            if (visited[c]) {
                continue;
            }
            visited[c] = true;
            while (top > 0 && stack[top - 1] > c) {
                if (counts[stack[top - 1]] > 0) {
                    visited[stack[--top]] = false;
                } else {
                    break;
                }
            }
            stack[top++] = c;
        }
        return new String(stack, 0, top);
    }
}
// @lc code=end
