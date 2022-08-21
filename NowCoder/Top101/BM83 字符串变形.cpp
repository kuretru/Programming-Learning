#include <string>
#include <vector>

class Solution {
  public:
    string trans(string s, int n) {
        string result = "";
        std::vector<string> words;
        for (int i = 0; i < n; i++) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                result += s[i] - 'A' + 'a';
            } else if ('a' <= s[i] && s[i] <= 'z') {
                result += s[i] - 'a' + 'A';
            } else {
                words.push_back(result);
                result = "";
            }
        }
        words.push_back(result);
        result = "";

        for (auto iter = words.rbegin(); iter != words.rend(); iter++) {
            if (iter != words.rbegin()) {
                result += " ";
            }
            result += *iter;
        }
        return result;
    }
};
