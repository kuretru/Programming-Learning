/*
 * @lc app=leetcode.cn id=832 lang=java
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int length = (A[0].length + 1) >> 1;
        for (int[] row : A) {
            for (int i = 0, j = A[0].length - 1; i < length; i++, j--) {
                int tmp = row[i];
                row[i] = row[j] ^ 1;
                row[j] = tmp ^ 1;
            }
        }
        return A;
    }
}
// @lc code=end
