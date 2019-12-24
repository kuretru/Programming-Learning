/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int index = 0, last = nums[0] - 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != last) {
                last = nums[i];
                nums[index++] = nums[i];
            }
        }
        return index;
    }
}
// @lc code=end
