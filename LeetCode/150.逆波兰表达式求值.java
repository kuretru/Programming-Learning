/*
 * @lc app=leetcode.cn id=150 lang=java
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new LinkedList<>();
        for (String token : tokens) {
            if (token.length() != 1 || Character.isDigit(token.charAt(0))) {
                stack.push(Integer.valueOf(token));
                continue;
            }
            int b = stack.pop();
            int a = stack.pop();
            char[] chars = token.toCharArray();
            switch (chars[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    break;
            }
        }
        return stack.pop();
    }
}
// @lc code=end
