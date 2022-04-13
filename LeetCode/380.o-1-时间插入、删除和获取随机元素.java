/*
 * @lc app=leetcode.cn id=380 lang=java
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
    private final List<Integer> list;
    private final Map<Integer, Integer> map;
    private final Random random;

    public RandomizedSet() {
        this.list = new ArrayList<>();
        this.map = new HashMap<>(16);
        this.random = new Random();
    }

    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        }
        list.add(val);
        map.put(val, list.size() - 1);
        return true;
    }

    public boolean remove(int val) {
        if (map.containsKey(val)) {
            int index = map.remove(val);
            int lastIndex = list.size() - 1;
            if (index != lastIndex) {
                int last = list.get(lastIndex);
                map.put(last, index);
                list.set(index, last);
            }
            list.remove(lastIndex);
            return true;
        }
        return false;
    }

    public int getRandom() {
        int index = random.nextInt(list.size());
        return list.get(index);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end
