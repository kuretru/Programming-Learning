// @lc code=start
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 0x1) == 1) {
                result++;
            }
            n >>>= 1;
        }
        return result;
    }
}
// @lc code=end
