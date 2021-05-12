/*
 * @lc app=leetcode.cn id=1310 lang=java
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] data = new int[arr.length];
        data[0] ^= arr[0];
        for (int i = 1; i < data.length; i++) {
            data[i] = data[i - 1] ^ arr[i];
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            result[i] = data[queries[i][1]];
            if (queries[i][0] > 0) {
                result[i] ^= data[queries[i][0] - 1];
            }
        }
        return result;
    }
}
// @lc code=end
