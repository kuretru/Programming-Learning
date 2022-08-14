class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        const int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (nums[i] <= 0 || nums[i] > length) {
                nums[i] = INT32_MAX;
            }
        }
        for (int i = 0; i < length; i++) {
            int value = std::abs(nums[i]);
            if (value <= length && nums[value - 1] > 0) {
                nums[value - 1] = -nums[value - 1];
            }
        }
        int result = length + 1;
        for (int i = 0; i < length; i++) {
            if (nums[i] > 0) {
                result = i + 1;
                break;
            }
        }
        return result;
    }
};
