/*
 * @lc app=leetcode.cn id=1081 lang=java
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
    public String smallestSubsequence(String s) {
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
