import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1018 lang=java
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        Boolean[] result = new Boolean[A.length];
        int number = 0;
        for (int i = 0; i < A.length; i++) {
            number = ((number << 1) + A[i]) % 5;
            result[i] = number == 0;
        }
        return Arrays.asList(result);
    }
}
// @lc code=end
