import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=455 lang=java
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int result = 0;
        for (int i = 0, j = 0; i < g.length && j < s.length; j++) {
            if (g[i] <= s[j]) {
                i++;
                result++;
            }
        }
        return result;
    }
}
// @lc code=end
