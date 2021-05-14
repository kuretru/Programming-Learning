import java.util.Scanner;

/*
 * @lc app=leetcode.cn id=12 lang=java
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
    String[] thousands = {"", "M", "MM", "MMM"};
    String[] hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String[] tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String[] ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    public String intToRoman(int num) {
        StringBuilder result = new StringBuilder();
        result.append(thousands[num / 1000]);
        result.append(hundreds[num / 100 % 10]);
        result.append(tens[num / 10 % 10]);
        result.append(ones[num % 10]);
        return result.toString();
    }
}
// @lc code=end
