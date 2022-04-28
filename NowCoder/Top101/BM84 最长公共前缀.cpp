class Solution {
  public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.size() == 0 || strs[0].size() == 0) {
            return result;
        }
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[i].size() || strs[j][i] != strs[0][i]) {
                    goto out;
                }
            }
            result += strs[0][i];
        }
out:
        return result;
    }
};
