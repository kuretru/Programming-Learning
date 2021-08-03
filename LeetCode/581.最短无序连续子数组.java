/*
 * @lc app=leetcode.cn id=581 lang=java
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] sorted = new int[nums.length];
        int result = nums.length;
        System.arraycopy(nums, 0, sorted, 0, result);
        Arrays.sort(sorted);
        if (Arrays.equals(nums, sorted)) {
            return 0;
        }
        for (int i = 0; i < nums.length && nums[i] == sorted[i]; i++) {
            result--;
        }
        for (int i = nums.length - 1; i > 0 && nums[i] == sorted[i]; i--) {
            result--;
        }
        return result;
    }
}
// @lc code=end
