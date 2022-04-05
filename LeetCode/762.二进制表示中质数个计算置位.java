/*
 * @lc app=leetcode.cn id=762 lang=java
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
    private static final boolean[] PRIMES = new boolean[]{false, false, true, true, false, true, false, true, false, false,
            false, true, false, true, false, false, false, true, false, true};

    public int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++) {
            int count = Integer.bitCount(i);
            if (PRIMES[count]) {
                result++;
            }
        }
        return result;
    }
}
// @lc code=end
