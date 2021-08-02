/*
 * @lc app=leetcode.cn id=743 lang=java
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
    public int networkDelayTime(int[][] times, int n, int start) {
        int[][] data = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(data[i], Integer.MAX_VALUE);
        }
        for (int[] time : times) {
            data[time[0]][time[1]] = Math.min(data[time[0]][time[1]], time[2]);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (data[i][k] != Integer.MAX_VALUE && data[k][j] != Integer.MAX_VALUE) {
                        data[i][j] = Math.min(data[i][j], data[i][k] + data[k][j]);
                    }
                }
            }
        }

        data[start][start] = 0;
        int time = 0;
        for (int i = 1; i <= n; i++) {
            if (data[start][i] == Integer.MAX_VALUE) {
                return -1;
            }
            time = Math.max(time, data[start][i]);
        }
        return time;
    }
}
// @lc code=end
