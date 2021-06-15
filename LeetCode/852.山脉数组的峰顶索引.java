/*
 * @lc app=leetcode.cn id=852 lang=java
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 1, high = arr.length - 2;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (arr[mid - 1] < arr[mid]) {
                low = mid + 1;
            } else if (arr[mid] > arr[mid + 1]) {
                high = mid - 1;
            }
        }
        return low;
    }
}
// @lc code=end
