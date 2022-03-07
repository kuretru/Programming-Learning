/*
 * @lc app=leetcode.cn id=2100 lang=java
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        List<Integer> result = new ArrayList<>();
        if (time << 1 >= security.length) {
            return result;
        }
        if (time == 0) {
            for (int i = 0; i < security.length; i++) {
                result.add(i);
            }
            return result;
        }
        int[] left = new int[security.length];
        int[] right = new int[security.length];
        for (int i = 1; i < security.length; i++) {
            if (security[i - 1] >= security[i]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = security.length - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        for (int i = time; i < security.length - time; i++) {
            if (left[i] >= time && right[i] >= time) {
                result.add(i);
            }
        }
        return result;
    }
}
// @lc code=end
