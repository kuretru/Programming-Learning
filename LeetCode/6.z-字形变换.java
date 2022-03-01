/*
 * @lc app=leetcode.cn id=6 lang=java
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        char[] data = s.toCharArray();
        char[] result = new char[data.length];
        int step = (numRows << 1) - 2;
        int groups = (data.length + step - 1) / step;
        int index = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < groups; j++) {
                int begin = j * step;
                if (begin + i < data.length) {
                    result[index++] = data[begin + i];
                }
                if (i == 0 || i == numRows - 1) {
                    continue;
                }
                if (begin + step - i < data.length) {
                    result[index++] = data[begin + step - i];
                }
            }
        }
        return new String(result);
    }
}
// @lc code=end
