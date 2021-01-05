import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=830 lang=java
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> result = new ArrayList<>();
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            for (int j = i + 1; j <= chars.length; j++) {
                if (j == chars.length || chars[j] != chars[i]) {
                    if (j - i >= 3) {
                        result.add(Arrays.asList(i, j - 1));
                    }
                    i = j - 1;
                    break;
                }
            }
        }
        return result;
    }
}
// @lc code=end
