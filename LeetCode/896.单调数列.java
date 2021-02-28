/*
 * @lc app=leetcode.cn id=896 lang=java
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
    public boolean isMonotonic(int[] A) {
        boolean increase = true;
        boolean decrease = true;
        for (int i = 1; i < A.length; i++) {
            if (A[i - 1] < A[i]) {
                increase = false;
            } else if (A[i - 1] > A[i]) {
                decrease = false;
            }
        }
        return increase || decrease;
    }
}
// @lc code=end
