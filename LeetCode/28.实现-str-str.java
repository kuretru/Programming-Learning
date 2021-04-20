/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null || haystack.length() < needle.length()) {
            return -1;
        } else if (needle.length() == 0) {
            return 0;
        }
        char[] text = haystack.toCharArray();
        char[] key = needle.toCharArray();
        int[] pmt = buildPmt(key);
        for (int i = 0, j = 0; i < text.length; ) {
            if (text[i] == key[j]) {
                i++;
                j++;
                if (j == key.length) {
                    return i - j;
                }
            } else if (j > 0) {
                j = pmt[j];
            } else {
                i++;
            }
        }
        return -1;
    }

    private int[] buildPmt(char[] key) {
        int[] pmt = new int[key.length];
        pmt[0] = -1;
        for (int i = 1; i < key.length; i++) {
            int j = pmt[i - 1];
            while (j >= 0 && (key[j + 1] != key[i])) {
                j = pmt[j];
            }
            if (key[j + 1] == key[i]) {
                pmt[i] = j + 1;
            } else {
                pmt[i] = -1;
            }
        }
        for (int i = key.length - 1; i > 0; i--) {
            pmt[i] = pmt[i - 1] + 1;
        }
        return pmt;
    }
}
// @lc code=end
