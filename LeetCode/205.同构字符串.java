/*
 * @lc app=leetcode.cn id=205 lang=java
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
    public boolean isIsomorphic(String s, String t) {
        char[] ss = s.toCharArray();
        char[] tt = t.toCharArray();
        char[] s2tMap = new char[255];
        boolean[] tUsed = new boolean[255];
        for (int i = 0; i < ss.length; i++) {
            if (s2tMap[ss[i]] == 0) {
                if (tUsed[tt[i]]) {
                    return false;
                }
                tUsed[tt[i]] = true;
                s2tMap[ss[i]] = tt[i];
            } else if (s2tMap[ss[i]] != tt[i]) {
                return false;
            }
        }
        return true;
    }
    }
}
// @lc code=end
