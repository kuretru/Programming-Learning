/*
 * @lc app=leetcode.cn id=80 lang=java
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length < 2) {
            return nums.length;
        }
        int second = nums[0];
        int last = nums[1];
        int result = 2;
        for (int i = 2; i < nums.length; i++) {
            if (second == last && last == nums[i]) {
                continue;
            }
            nums[result++] = nums[i];
            second = last;
            last = nums[i];
        }
        return result;
    }
}
// @lc code=end
