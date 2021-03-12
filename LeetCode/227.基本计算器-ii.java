/*
 * @lc app=leetcode.cn id=227 lang=java
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
    private static final int[] PRIORITY = new int[255];

    static {
        PRIORITY['*'] = PRIORITY['/'] = 4;
        PRIORITY['+'] = PRIORITY['-'] = 5;
    }

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
            } else if (chars[i] != ')') {
                while (!operators.isEmpty() && PRIORITY[operators.peek()] <= PRIORITY[chars[i]]) {
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
        switch (operator) {
            case '+':
                numbers.push(a + b);
                break;
            case '-':
                numbers.push(a - b);
                break;
            case '*':
                numbers.push(a * b);
                break;
            case '/':
                numbers.push(a / b);
                break;
            default:
                throw new UnsupportedOperationException("Unsupported operator: " + operator);
        }
    }
}
// @lc code=end
