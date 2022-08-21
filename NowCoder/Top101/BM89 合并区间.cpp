#include <algorithm>
#include <vector>

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }
        std::sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals.front());
        for (auto iter = intervals.begin() + 1; iter != intervals.end(); iter++) {
            if (iter->start <= result.back().end) {
                result.back().end = std::max(result.back().end, iter->end);
            } else {
                result.push_back(*iter);
            }
        }
        return result;
    }
  private:
    static bool compare(const Interval& x, const Interval& y) {
        return x.start < y.start;
    }
};
