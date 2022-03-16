/*
 * @lc app=leetcode.cn id=432 lang=java
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
    private final Map<String, Integer> data;
    private final TreeMap<Integer, Set<String>> timesMap;

    public AllOne() {
        this.data = new HashMap<>(16);
        this.timesMap = new TreeMap<>();
    }

    public void inc(String key) {
        int value = data.getOrDefault(key, 0) + 1;
        data.put(key, value);
        Set<String> set = timesMap.getOrDefault(value, new HashSet<>());
        set.add(key);

        timesMap.put(value, set);
        if (value > 1) {
            timesMap.get(value - 1).remove(key);
            if (timesMap.get(value - 1).isEmpty()) {
                timesMap.remove(value - 1);
            }
        }
    }

    public void dec(String key) {
        int value = data.get(key) - 1;
        data.put(key, value);
        if (value == 0) {
            data.remove(key);
        } else {
            Set<String> set = timesMap.getOrDefault(value, new HashSet<>());
            set.add(key);
            timesMap.put(value, set);
        }
        timesMap.get(value + 1).remove(key);
        if (timesMap.get(value + 1).isEmpty()) {
            timesMap.remove(value + 1);
        }
    }

    public String getMaxKey() {
        if (timesMap.isEmpty()) {
            return "";
        }
        for (String key : timesMap.lastEntry().getValue()) {
            return key;
        }
        return "";
    }

    public String getMinKey() {
        if (timesMap.isEmpty()) {
            return "";
        }
        for (String key : timesMap.firstEntry().getValue()) {
            return key;
        }
        return "";
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
// @lc code=end
