/*
 * @lc app=leetcode.cn id=59 lang=java
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    private static final int[][] DIRECTION = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int length = n * n;
        int step = 0;
        for (int i = 1, j = 0, k = 0; i <= length; i++) {
            result[j][k] = i;
            int x = j + DIRECTION[step][0];
            int y = k + DIRECTION[step][1];
            if (x < 0 || x >= n || y < 0 || y >= n || result[x][y] != 0) {
                step = (step + 1) % 4;
            }
            j += DIRECTION[step][0];
            k += DIRECTION[step][1];
        }
        return result;
    }
}
// @lc code=end
