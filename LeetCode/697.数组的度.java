/*
 * @lc app=leetcode.cn id=697 lang=java
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {

    private static final Integer MAX_LENGTH = 50001;

    public int findShortestSubArray(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        Number[] data = new Number[MAX_LENGTH];
        for (int i = 0; i < nums.length; i++) {
            if (data[nums[i]] == null) {
                data[nums[i]] = new Number();
            }
            data[nums[i]].count++;
            if (data[nums[i]].left == -1) {
                data[nums[i]].left = i;
            }
            data[nums[i]].right = i;
        }
        int degree = 0;
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (data[i] != null) {
                degree = Math.max(degree, data[i].count);
            }
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (data[i] != null && data[i].count == degree) {
                int length = nums.length - data[i].left - (nums.length - 1 - data[i].right);
                result = Math.min(result, length);
            }
        }
        return result;
    }

}

class Number {

    int count = 0;
    int left = -1;
    int right = -1;

}
// @lc code=end
