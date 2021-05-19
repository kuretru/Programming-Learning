/*
 * @lc app=leetcode.cn id=1738 lang=java
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] prefixSum = new int[m + 1][n + 1];
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(m * n, (n1, n2) -> n2 - n1);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j - 1] ^ prefixSum[i - 1][j] ^ prefixSum[i][j - 1] ^ matrix[i - 1][j - 1];
                maxHeap.add(prefixSum[i][j]);
            }
        }
        while (--k > 0) {
            maxHeap.poll();
        }
        return maxHeap.peek();
    }
}
// @lc code=end
