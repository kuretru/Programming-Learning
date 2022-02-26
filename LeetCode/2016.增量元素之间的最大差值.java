/*
 * @lc app=leetcode.cn id=2016 lang=java
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
    public int maximumDifference(int[] nums) {
        int result = -1, preMin = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > preMin) {
                result = Math.max(result, nums[i] - preMin);
            } else {
                preMin = Math.min(preMin, nums[i]);
            }
        }
        return result;
    }
}
// @lc code=end
