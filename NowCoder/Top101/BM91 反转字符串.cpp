#include <string>

class Solution {
  public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            std::swap(str[i], str[j]);
        }
        return str;
    }
};
