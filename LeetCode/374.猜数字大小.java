/*
 * @lc app=leetcode.cn id=374 lang=java
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        // high = 2^31 - 1
        int low = 1, high = ~(1 << 31);
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            int guess = guess(mid);
            if (-1 == guess) {
                high = mid - 1;
            } else if (1 == guess) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low;
    }
}
// @lc code=end
