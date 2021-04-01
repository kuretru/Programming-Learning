import java.util.Deque;
import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=1006 lang=java
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
    public int clumsy(int N) {
        Deque<Integer> queue = new LinkedList<>();
        int number = -1;
        for (int i = N, j = 0; i > 0; i--, j++) {
            switch (j % 4) {
                case 0:
                    number = i;
                    break;
                case 1:
                    number *= i;
                    break;
                case 2:
                    number /= i;
                    break;
                case 3:
                    queue.addFirst(number);
                    queue.addFirst(i);
                    number = 0;
                    break;
                default:
            }
        }
        if (queue.isEmpty()) {
            return number;
        }
        if (number != 0) {
            queue.addFirst(number);
        }
        number = queue.removeLast();
        int flag = 1;
        while (!queue.isEmpty()) {
            number += flag * queue.removeLast();
            flag *= -1;
        }
        return number;
    }
}
// @lc code=end
