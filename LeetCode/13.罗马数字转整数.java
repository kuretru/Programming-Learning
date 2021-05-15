/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
    private static final char[] RULES = new char[255];
    static {
        RULES['I'] = 1;
        RULES['V'] = 5;
        RULES['X'] = 10;
        RULES['L'] = 50;
        RULES['C'] = 100;
        RULES['D'] = 500;
        RULES['M'] = 1000;
    }
    public int romanToInt(String s) {
        char[] chars = s.toCharArray();
        int result = 0;
        for (int i = 0; i < chars.length; i++) {
            int value = RULES[chars[i]];
            if (i + 1 < chars.length && value < RULES[chars[i + 1]]) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }
}
// @lc code=end
