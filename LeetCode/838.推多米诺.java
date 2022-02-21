/*
 * @lc app=leetcode.cn id=838 lang=java
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution {
    private int findDotSequencesEnd(char[] data, int begin) {
        int end = begin + 1;
        while (end < data.length && data[end] == '.') {
            end++;
        }
        return end - 1;
    }

    private char inferLeftTrend(char[] data, int index) {
        return index > 0 ? data[index - 1] : 'L';
    }

    private char inferRightTrend(char[] data, int index) {
        return index + 1 < data.length ? data[index + 1] : 'R';
    }

    public String pushDominoes(String dominoes) {
        char[] data = dominoes.toCharArray();
        for (int begin = 0; begin < data.length; begin++) {
            if (data[begin] != '.') {
                continue;
            }
            int end = findDotSequencesEnd(data, begin);
            char leftTrend = inferLeftTrend(data, begin);
            char rightTrend = inferRightTrend(data, end);
            if (leftTrend == rightTrend) {
                Arrays.fill(data, begin, end + 1, leftTrend);
            }
            if (leftTrend == 'R' && rightTrend == 'L') {
                for (int i = begin, j = end; i < j; i++, j--) {
                    data[i] = 'R';
                    data[j] = 'L';
                }
            }
            begin = end + 1;
        }
        return new String(data);
    }
}
// @lc code=end
