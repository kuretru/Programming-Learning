/*
 * @lc app=leetcode.cn id=401 lang=java
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < 1024; i++) {
            int hour = i >> 6, minute = i & 0b111111;
            if (hour < 12 && minute < 60 && Integer.bitCount(i) == turnedOn) {
                result.add(hour + ":" + (minute < 10 ? "0" : "") + minute);
            }
        }
        return result;
    }
}
// @lc code=end
