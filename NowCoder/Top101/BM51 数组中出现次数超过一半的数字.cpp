#include <vector>

class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return -1;
        }
        int flag = numbers[0];
        int count = 1;
        for (auto iter = numbers.begin() + 1; iter != numbers.end(); iter++) {
            if (flag == *iter) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    flag = *iter;
                    count = 1;
                }
            }
        }
        return flag;
    }
};
