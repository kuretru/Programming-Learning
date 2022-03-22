/*
 * @lc app=leetcode.cn id=2038 lang=java
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

// @lc code=start
class Solution {
    public boolean winnerOfGame(String colors) {
        char[] data = colors.toCharArray();
        int a = 0, b = 0;
        for (int i = 0; i < data.length; ) {
            int end = i + 1;
            while (end < data.length && data[end] == data[i]) {
                end++;
            }
            int count = end - i - 2;
            if (count > 0) {
                if (data[i] == 'A') {
                    a += count;
                } else {
                    b += count;
                }
            }
            i = end;
        }
        return a > b;
    }
}
// @lc code=end
