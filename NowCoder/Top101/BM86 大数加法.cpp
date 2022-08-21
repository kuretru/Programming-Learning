#include <string>

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        int carry = 0;
        int i = s.size() - 1;
        int j = t.size() - 1;
        string result = "";
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += s[i--] - '0';
            }
            if (j >= 0) {
                sum += t[j--] - '0';
            }
            carry = sum / 10;
            result = to_string(sum % 10) + result;
        }
        if (carry > 0) {
            result = to_string(carry) + result;
        }
        return result;
    }
};
