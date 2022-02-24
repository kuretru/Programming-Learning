/*
 * @lc app=leetcode.cn id=1706 lang=java
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
    private boolean stuckLeft(int[] row, int index) {
        return row[index] == 1 && (index + 1 == row.length || row[index + 1] == -1);
    }

    private boolean stuckRight(int[] row, int index) {
        return row[index] == -1 && (index == 0 || row[index - 1] == 1);
    }

    public int[] findBall(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] result = new int[n];
        for (int col = 0; col < n; col++) {
            result[col] = col;
            for (int row = 0; row < m; row++) {
                int index = result[col];
                if (stuckLeft(grid[row], index) || stuckRight(grid[row], index)) {
                    result[col] = -1;
                    break;
                }
                result[col] += grid[row][index];
            }
        }
        return result;
    }
}
// @lc code=end
