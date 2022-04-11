/*
 * @lc app=leetcode.cn id=357 lang=java
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        }
        int result = 10;
        int time = 9;
        int count = 9;
        for (int i = 1; i < n; i++) {
            time *= count;
            result += time;
            count--;
        }
        return result;
    }
}
// @lc code=end
