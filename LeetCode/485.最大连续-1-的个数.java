/*
 * @lc app=leetcode.cn id=485 lang=java
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int result = 0;
        for (int i = 0, count = 0; i <= nums.length; i++) {
            if (i == nums.length || nums[i] == 0) {
                result = Math.max(result, count);
                count = 0;
            } else {
                count++;
            }
        }
        return result;
    }
}
// @lc code=end
