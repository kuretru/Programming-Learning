/*
 * @lc app=leetcode.cn id=88 lang=java
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int length = m + n;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[--length] = nums1[--m];
            } else {
                nums1[--length] = nums2[--n];
            }
        }
        while (m > 0) {
            nums1[--length] = nums1[--m];
        }
        while (n > 0) {
            nums1[--length] = nums2[--n];
        }
    }
}
// @lc code=end
