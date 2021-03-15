/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    private static final int[][] DIRECTION = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = m == 0 ? 0 : matrix[0].length;
        Integer[] result = new Integer[m * n];
        boolean[][] visited = new boolean[m][n];
        int step = 0;
        for (int i = 0, j = 0, k = 0; i < result.length; i++) {
            result[i] = matrix[j][k];
            visited[j][k] = true;
            int x = j + DIRECTION[step][0];
            int y = k + DIRECTION[step][1];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
                step = (step + 1) % 4;
            }
            j += DIRECTION[step][0];
            k += DIRECTION[step][1];
        }
        return Arrays.asList(result);
    }
}
// @lc code=end
