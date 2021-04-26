/*
 * @lc app=leetcode.cn id=1011 lang=java
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int sum = 0;
        int max = 0;
        for (int weight : weights) {
            sum += weight;
            max = Math.max(max, weight);
        }
        int left = max;
        int right = sum;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (canShipInDays(weights, D, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean canShipInDays(int[] weights, int D, int capability) {
        int ship = capability;
        for (int weight : weights) {
            if (D <= 0) {
                return false;
            }
            if (ship - weight >= 0) {
                ship -= weight;
            } else {
                ship = capability - weight;
                D--;
            }
        }
        return D > 0;
    }
}
// @lc code=end
