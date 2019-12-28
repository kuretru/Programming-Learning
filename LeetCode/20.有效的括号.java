import java.util.Stack;

/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        char[] text = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < text.length; i++) {
            if (text[i] == '(' || text[i] == '{' || text[i] == '[') {
                stack.add(text[i]);
            } else if (stack.empty()) {
                return false;
            } else {
                char top = stack.pop();
                if (top == '(' && text[i] != ')') {
                    return false;
                } else if (top == '{' && text[i] != '}') {
                    return false;
                } else if (top == '[' && text[i] != ']') {
                    return false;
                }
            }
        }
        return stack.empty();
    }
}
// @lc code=end
