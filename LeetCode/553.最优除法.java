/*
 * @lc app=leetcode.cn id=553 lang=java
 *
 * [553] 最优除法
 */

// @lc code=start
class Solution {
    public String optimalDivision(int[] nums) {
        StringBuilder result = new StringBuilder();
        if (nums.length == 1) {
            return String.valueOf(nums[0]);
        } else if (nums.length == 2) {
            return result.append(nums[0]).append('/').append(nums[1]).toString();
        }
        result.append(nums[0]).append("/(");
        for (int i = 1; i < nums.length; i++) {
            result.append(nums[i]);
            result.append((i + 1 == nums.length) ? ')' : '/');
        }
        return result.toString();
    }
}
// @lc code=end
