/*
 * @lc app=leetcode.cn id=307 lang=java
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
    private final int length;
    private final int[] nums;
    private final int[] binaryIndexedTree;

    public NumArray(int[] nums) {
        this.length = nums.length;
        this.nums = nums;
        binaryIndexedTree = new int[this.length + 1];
        for (int i = 1; i <= this.length; i++) {
            for (int j = i; j <= nums.length; j += lowBit(j)) {
                binaryIndexedTree[j] += nums[i - 1];
            }
        }
    }

    public void update(int index, int val) {
        int difference = val - nums[index];
        nums[index] = val;
        for (int j = index + 1; j <= nums.length; j += lowBit(j)) {
            binaryIndexedTree[j] += difference;
        }
    }

    private int preSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += binaryIndexedTree[index];
            index -= lowBit(index);
        }
        return sum;
    }

    public int sumRange(int left, int right) {
        return preSum(right + 1) - preSum(left);
    }

    private int lowBit(int n) {
        return n & (-n);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
// @lc code=end
