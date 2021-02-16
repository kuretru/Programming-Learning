/*
 * @lc app=leetcode.cn id=118 lang=java
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            Integer[] row = new Integer[i + 1];
            row[0] = 1;
            for (int j = 1; j <= i; j++) {
                row[j] = (int) ((long) row[j - 1] * (i - j + 1) / j);
            }
            result.add(Arrays.asList(row));
        }
        return result;
    }
}
// @lc code=end
