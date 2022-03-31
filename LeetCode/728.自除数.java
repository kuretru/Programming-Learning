/*
 * @lc app=leetcode.cn id=728 lang=java
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
    private boolean isSelfDividingNumber(int number) {
        int tmp = number;
        while (tmp > 0) {
            int n = tmp % 10;
            if (n == 0) {
                return false;
            } else if (number % n != 0) {
                return false;
            }
            tmp /= 10;
        }
        return true;
    }

    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> result = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i)) {
                result.add(i);
            }
        }
        return result;
    }
}
// @lc code=end
