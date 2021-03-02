/*
 * @lc app=leetcode.cn id=304 lang=java
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
    private final int[][] data;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix.length > 0 ? matrix[0].length : 0;
        this.data = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                this.data[i + 1][j + 1] = this.data[i][j + 1] + matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                this.data[i + 1][j + 1] += this.data[i + 1][j];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return data[row2 + 1][col2 + 1] - data[row2 + 1][col1] - data[row1][col2 + 1] + data[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
