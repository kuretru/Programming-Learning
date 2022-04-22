/*
 * @lc app=leetcode.cn id=396 lang=java
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
    public int maxRotateFunction(int[] nums) {
        int sum = 0;
        int f0 = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            f0 += i * nums[i];
        }
        int result = f0;
        for (int i = nums.length - 1; i >= 0; i--) {
            f0 += sum - nums.length * nums[i];
            result = Math.max(result, f0);
        }
        return result;
    }
}
// @lc code=end
