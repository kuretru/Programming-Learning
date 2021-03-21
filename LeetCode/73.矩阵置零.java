/*
 * @lc app=leetcode.cn id=73 lang=java
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] rows = new int[]{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
        int[] cols = new int[]{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if ((rows[i >> 5] & 1 << (i & 0x1f)) != 0) {
                        rows[i >> 5] ^= 1 << (i & 0x1f);
                    }
                    if ((cols[j >> 5] & 1 << (j & 0x1f)) != 0) {
                        cols[j >> 5] ^= 1 << (j & 0x1f);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((rows[i >> 5] & 1 << (i & 0x1f)) == 0 || (cols[j >> 5] & 1 << (j & 0x1f)) == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
// @lc code=end
