#include <algorithm>
#include <queue>
#include <vector>

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int>>& startEnd) {
        std::sort(startEnd.begin(), startEnd.end(), compare);
        std::priority_queue<int, vector<int>, std::greater<int>> heap;
        heap.push(INT32_MIN);
        for (auto iter = startEnd.begin(); iter != startEnd.end(); iter++) {
            if (heap.top() <= (*iter)[0]) {
                heap.pop();
            }
            heap.push((*iter)[1]);
        }
        return heap.size();
    }
  private:
    static bool compare(const vector<int>& x, const vector<int>& y) {
        assert(x.size() == 2 && y.size() == 2);
        if (x[0] != y[0])
            return x[0] < y[0];
        return x[1] < y[1];
    }
};
