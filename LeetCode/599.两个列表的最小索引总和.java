/*
 * @lc app=leetcode.cn id=599 lang=java
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<>((int)(list1.length / 0.75));
        for (int i = 0; i < list1.length; i++) {
            map.put(list1[i], i);
        }
        int min = Integer.MAX_VALUE;
        List<String> result = new ArrayList<>();
        for (int i = 0; i < list2.length && i <= min; i++) {
            String key = list2[i];
            if (map.containsKey(key)) {
                int sum = map.get(key) + i;
                if (sum < min) {
                    min = sum;
                    result.clear();
                    result.add(key);
                } else if (sum == min) {
                    result.add(key);
                }
            }
        }
        return result.toArray(new String[0]);
    }
}
// @lc code=end
