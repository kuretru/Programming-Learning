#include <vector>
#include <unordered_map>

class Solution {
  public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> map;
        vector<int>result;
        for (int i = 0; i < numbers.size(); i++) {
            if (!map.count(target - numbers[i])) {
                map[numbers[i]] = i;
                continue;
            }
            int x = i + 1;
            int y = map[target - numbers[i]] + 1;
            result.push_back(std::min(x, y));
            result.push_back(std::max(x, y));
            break;
        }
        return result;
    }
};
