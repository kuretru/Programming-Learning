import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> data = new HashMap<>(128);
        for (int i = 0; i < nums.length; i++) {
            if (!data.containsKey(nums[i])) {
                data.put(nums[i], i);
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (data.containsKey(target - nums[i]) && data.get(target - nums[i]) != i) {
                return new int[] { i, data.get(target - nums[i]) };
            }
        }
        return new int[2];
    }
}
// @lc code=end
