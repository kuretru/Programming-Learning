import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=909 lang=java
 *
 * [909] 蛇梯棋
 */

// @lc code=start
class Status {
    int position;
    int step;

    public Status(int position, int step) {
        this.position = position;
        this.step = step;
    }
}

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int destination = n * n;
        boolean[] visited = new boolean[destination + 1];
        Queue<Status> queue = new LinkedList<>();
        queue.add(new Status(1, 0));
        while (!queue.isEmpty()) {
            Status peek = queue.poll();
            if (peek.position == destination) {
                return peek.step;
            }
            for (int i = 1; i <= 6; i++) {
                if (peek.position + i > destination) {
                    continue;
                }
                int next = moveToNext(board, peek.position + i);
                if (next != -1 && !visited[next]) {
                    visited[next] = true;
                    queue.add(new Status(next, peek.step + 1));
                }
            }
        }
        return -1;
    }

    private int moveToNext(int[][] board, int target) {
        int n = board.length;
        int x = n - 1 - (target - 1) / n;
        int y = (target - 1) % n;
        if (n % 2 == x % 2) {
            y = n - y - 1;
        }
        if (board[x][y] != -1) {
            return board[x][y];
        }
        return target;
    }
}
// @lc code=end
