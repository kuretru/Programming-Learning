/*
 * @lc app=leetcode.cn id=224 lang=java
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
    public int calculate(String s) {
        char[] chars = s.toCharArray();
        Deque<Character> operators = new LinkedList<>();
        Deque<Integer> numbers = new LinkedList<>();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == ' ') {
                continue;
            }
            if (Character.isDigit((chars[i]))) {
                int number = chars[i] - '0', j = i + 1;
                for (; j < chars.length && Character.isDigit(chars[j]); j++) {
                    number = number * 10 + (chars[j] - '0');
                }
                i = j - 1;
                numbers.push(number);
            } else if (chars[i] == '(') {
                operators.push(chars[i]);
            } else if (chars[i] == '+' || chars[i] == '-') {
                if (!operators.isEmpty() && operators.peek() != '(') {
                    computeTop(operators, numbers);
                }
                operators.push(chars[i]);
            } else if (chars[i] == ')') {
                for (char operator = operators.peek(); operator != '('; operator = operators.peek()) {
                    computeTop(operators, numbers);
                }
                operators.pop();
            }
        }
        while (!operators.isEmpty()) {
            computeTop(operators, numbers);
        }
        return numbers.pop();
    }

    private void computeTop(Deque<Character> operators, Deque<Integer> numbers) {
        int b = numbers.pop();
        if (numbers.isEmpty()) {
            numbers.push(-b);
            operators.pop();
            return;
        }
        int a = numbers.pop();
        char operator = operators.pop();
        if (operator == '+') {
            numbers.push(a + b);
        } else {
            numbers.push(a - b);
        }
    }
}
// @lc code=end
