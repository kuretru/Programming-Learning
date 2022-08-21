#include <string>
#include <unordered_map>

class Solution {
  private:
    bool all_found(std::unordered_map<char, int> found) {
        for (auto iter = found.begin(); iter != found.end(); iter++)
            if (iter->second < 0)
                return false;
        return true;
    }
  public:
    /**
     *
     * @param S string字符串
     * @param T string字符串
     * @return string字符串
     */
    string minWindow(string S, string T) {
        std::unordered_map<char, int> found;
        for (auto iter = T.begin(); iter != T.end(); iter++) {
            found[*iter]--;
        }
        int left = 0, right = 0;
        int min = INT32_MAX, min_left = 0, min_right = 0;
        for (; right < S.length(); right++) {
            if (found.count(S[right])) {
                found[S[right]]++;
            }
            while (all_found(found)) {
                if (right - left < min) {
                    min = right - left;
                    min_left = left;
                    min_right = right;
                }
                if (found.count(S[left])) {
                    found[S[left]]--;
                }
                left++;
            }
        }
        if (min == INT32_MAX)
            return "";
        return string(S.begin() + min_left, S.begin() + min_right + 1);
    }
};
