/*
 * @lc app=leetcode.cn id=2055 lang=java
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        char[] data = s.toCharArray();
        int[] leftPlateCount = new int[data.length];
        int[] lastCandleIndex = new int[data.length];
        int[] nextCandleIndex = new int[data.length];
        for (int i = 1; i < data.length; i++) {
            leftPlateCount[i] = leftPlateCount[i - 1];
            if (data[i - 1] == '*') {
                leftPlateCount[i]++;
            }
        }
        int last = -1;
        for (int i = 0; i < data.length; i++) {
            if (data[i] == '|') {
                last = i;
            }
            lastCandleIndex[i] = last;
        }
        int next = -1;
        for (int i = data.length - 1; i >= 0; i--) {
            if (data[i] == '|') {
                next = i;
            }
            nextCandleIndex[i] = next;
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int begin = queries[i][0], end = queries[i][1];
            if (nextCandleIndex[begin] == -1 || lastCandleIndex[end] == -1) {
                continue;
            }
            if (nextCandleIndex[begin] < lastCandleIndex[end]) {
                result[i] = leftPlateCount[lastCandleIndex[end]] - leftPlateCount[nextCandleIndex[begin]];
            }
        }
        return result;
    }
}
// @lc code=end
