#include <vector>

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int all = 0;
        for (auto iter = array.begin(); iter != array.end(); iter++) {
            all ^= *iter;
        }
        int one_bit = (all - 1) & all ^ all;
        int x = 0;
        for (auto iter = array.begin(); iter != array.end(); iter++) {
            if ((*iter & one_bit) == one_bit) {
                x ^= *iter;
            }
        }
        int y = all ^ x;

        vector<int>result;
        result.push_back(std::min(x, y));
        result.push_back(std::max(x, y));
        return result;
    }
};
