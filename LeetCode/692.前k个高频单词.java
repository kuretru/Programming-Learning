/*
 * @lc app=leetcode.cn id=692 lang=java
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap<>(16);
        for (String word : words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<Map.Entry<String, Integer>> maxHeap = new PriorityQueue<>((entry1, entry2) -> {
            if (entry1.getValue() != entry2.getValue()) {
                return entry1.getValue() - entry2.getValue();
            }
            return entry2.getKey().compareTo(entry1.getKey());
        });
        for (Map.Entry<String, Integer> entry : count.entrySet()) {
            maxHeap.offer(entry);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }
        List<String> result = new ArrayList<>();
        while (!maxHeap.isEmpty()) {
            result.add(maxHeap.poll().getKey());
        }
        Collections.reverse(result);
        return result;
    }
}
// @lc code=end
