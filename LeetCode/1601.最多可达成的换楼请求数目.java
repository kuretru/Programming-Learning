/*
 * @lc app=leetcode.cn id=1601 lang=java
 *
 * [1601] 最多可达成的换楼请求数目
 */

// @lc code=start
class Solution {
    public int maximumRequests(int n, int[][] requests) {
        int[] diff = new int[n];
        int result = 0;
        for (int i = (1 << requests.length) - 1; i >= 0; i--) {
            if (result > Integer.bitCount(i)) {
                continue;
            }
            Arrays.fill(diff, 0);
            for (int j = 0, k = 1; j < requests.length; j++, k <<= 1) {
                if ((i & k) == k) {
                    diff[requests[j][0]]--;
                    diff[requests[j][1]]++;
                }
            }
            boolean allZero = true;
            for (int j = 0; j < n; j++) {
                if (diff[j] != 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero) {
                result = Integer.bitCount(i);
            }
        }
        return result;
    }
}
// @lc code=end
