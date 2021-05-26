/*
 * @lc app=leetcode.cn id=1190 lang=java
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
    public String reverseParentheses(String s) {
        Deque<String> stack = new LinkedList<>();
        StringBuilder result = new StringBuilder();
        char[] chars = s.toCharArray();
        for (char c : chars) {
            if (c == '(') {
                stack.push(result.toString());
                result.setLength(0);
            } else if (c == ')') {
                result.reverse();
                result.insert(0, stack.pop());
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
}
// @lc code=end
