#include <algorithm>
#include <vector>

class Solution {
  public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int>& arr) {
        int length = arr.size();
        vector<int>data(length, 1);
        for (int i = 1; i < length; i++) {
            if (arr[i - 1] < arr[i]) {
                data[i] = data[i - 1] + 1;
            }
        }
        int result = data[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1] && data[i] <= data[i + 1]) {
                data[i] = data[i + 1] + 1;
            }
            result += data[i];
        }
        return result;
    }
};
