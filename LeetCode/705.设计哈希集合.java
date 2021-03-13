/*
 * @lc app=leetcode.cn id=705 lang=java
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet {
    private final boolean[][] data;

    /** Initialize your data structure here. */
    public MyHashSet() {
        this.data = new boolean[1001][1000];
    }

    public void add(int key) {
        data[key / 1000][key % 1000] = true;
    }

    public void remove(int key) {
        data[key / 1000][key % 1000] = false;
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return data[key / 1000][key % 1000];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
// @lc code=end
