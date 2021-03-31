/*
 * @lc app=leetcode.cn id=74 lang=java
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix.length > 0 ? matrix[0].length : 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == target) {
                return true;
            } else if (matrix[i][0] < target) {
                if (i + 1 == m || matrix[i + 1][0] > target) {
                    for (int j = 0; j < n; j++) {
                        if (matrix[i][j] == target) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}
// @lc code=end
