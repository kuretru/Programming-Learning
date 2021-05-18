/*
 * @lc app=leetcode.cn id=1442 lang=java
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
class Solution {
    public int countTriplets(int[] arr) {
        int length = arr.length;
        int[] prefixSum = new int[length + 1];
        prefixSum[0] = arr[0];
        for (int i = 0; i < length; i++) {
            prefixSum[i + 1] = prefixSum[i] ^ arr[i];
        }
        int result = 0;
        for (int i = 0; i < length; i++) {
            for (int k = i + 1; k < length; k++) {
                if (prefixSum[i] == prefixSum[k + 1]) {
                    result += k - i;
                }
            }
        }
        return result;
    }
}
// @lc code=end
