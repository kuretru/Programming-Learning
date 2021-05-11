/*
 * @lc app=leetcode.cn id=1734 lang=java
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
class Solution {
    public int[] decode(int[] encoded) {
        int n = encoded.length + 1;
        int total = 0;
        int odd = 0;
        for (int i = 1; i <= n; i++) {
            total ^= i;
        }
        for (int i = 1; i < encoded.length; i += 2) {
            odd ^= encoded[i];
        }
        int[] result = new int[n];
        result[0] = total ^ odd;
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] ^ encoded[i - 1];
        }
        return result;
    }
}
// @lc code=end
