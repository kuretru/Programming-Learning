/*
 * @lc app=leetcode.cn id=605 lang=java
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i = 0; i < flowerbed.length && n > 0; i++) {
            if (flowerbed[i] == 1) {
                continue;
            }
            boolean leftEmpty = i == 0 || (flowerbed[i - 1] == 0);
            boolean rightEmpty = i == flowerbed.length - 1 || (flowerbed[i + 1] == 0);
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
}
// @lc code=end
