/*
 * @lc app=leetcode.cn id=179 lang=java
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
    public String largestNumber(int[] nums) {
        Integer[] data = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(data, (x, y) -> {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return (int)(-sy * x - y + sx * y + x);
        });

        if (data[0] == 0) {
            return "0";
        }
        StringBuilder result = new StringBuilder();
        for (int n : data) {
            result.append(n);
        }
        return result.toString();
    }
}
// @lc code=end
