/*
 * @lc app=leetcode.cn id=354 lang=java
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes == null || envelopes.length == 0) {
            return 0;
        }

        Arrays.sort(envelopes, (o1, o2) -> {
            if (o1[0] != o2[0]) {
                return o1[0] - o2[0];
            } else {
                return o1[1] - o2[1];
            }
        });

        int[] lis = new int[envelopes.length];
        int result = 1;
        Arrays.fill(lis, 1);
        for (int i = 1; i < lis.length; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    lis[i] = Math.max(lis[i], lis[j] + 1);
                }
            }
            result = Math.max(result, lis[i]);
        }
        return result;
    }
}
// @lc code=end
