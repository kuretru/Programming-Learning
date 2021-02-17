/*
 * @lc app=leetcode.cn id=566 lang=java
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums.length * nums[0].length != r * c) {
            return nums;
        }
        int[][] result = new int[r][c];
        for (int i = 0, k = 0, l = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result[i][j] = nums[k][l++];
                if (l >= nums[0].length) {
                    k++;
                    l = 0;
                }
            }
        }
        return result;
    }
}
// @lc code=end
