/*
 * @lc app=leetcode.cn id=883 lang=java
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
    public int projectionArea(int[][] grid) {
        int n = grid.length;
        int result = 0;
        for (int i = 0; i < n; i++) {
            int xMax = 0;
            int yMax = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    result++;
                }
                xMax = Math.max(xMax, grid[i][j]);
                yMax = Math.max(yMax, grid[j][i]);
            }
            result += xMax;
            result += yMax;
        }
        return result;
    }
}
// @lc code=end
