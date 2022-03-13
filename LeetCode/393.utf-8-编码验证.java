/*
 * @lc app=leetcode.cn id=393 lang=java
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
    public boolean validUtf8(int[] data) {
        for (int i = 0; i < data.length; i++) {
            if (data[i] < 128) {
                continue;
            } else if (data[i] < 192 || data[i] >= 248) {
                return false;
            }
            if (data[i] < 0xe0) {
                if (i + 1 >= data.length || data[i + 1] < 128) {
                    return false;
                }
                i += 1;
            } else if (data[i] < 0xf0) {
                if (i + 2 >= data.length || data[i + 1] < 128 || data[i + 2] < 128) {
                    return false;
                }
                i += 2;
            } else if (data[i] < 0xf8) {
                if (i + 3 >= data.length || data[i + 1] < 128 || data[i + 2] < 128 || data[i + 3] < 128) {
                    return false;
                }
                i += 3;
            }
        }
        return true;
    }
}
// @lc code=end
