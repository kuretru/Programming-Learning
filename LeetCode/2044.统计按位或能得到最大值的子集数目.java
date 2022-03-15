/*
 * @lc app=leetcode.cn id=2044 lang=java
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
    private int solve(int[] nums, int max, int index, int sum) {
        if (index == nums.length) {
            return max == sum ? 1 : 0;
        }
        int x = 0;
        if ((sum | nums[index]) == max) {
            x = 1 << nums.length - index - 1;
        } else {
            x = solve(nums, max, index + 1, sum | nums[index]);
        }
        int y = solve(nums, max, index + 1, sum);
        return x + y;
    }

    public int countMaxOrSubsets(int[] nums) {
        int max = 0;
        for (int num : nums) {
            max |= num;
        }
        return solve(nums, max, 0, 0);
    }
}
// @lc code=end
