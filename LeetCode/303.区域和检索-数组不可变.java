/*
 * @lc app=leetcode.cn id=303 lang=java
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    private final int[] data;

    public NumArray(int[] nums) {
        this.data = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            this.data[i + 1] = this.data[i] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
        return this.data[j + 1] - this.data[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
// @lc code=end
