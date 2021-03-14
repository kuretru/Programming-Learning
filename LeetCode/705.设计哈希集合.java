import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=705 lang=java
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet {
    private static final int BASE = 997;
    private final Node[] data;

    /** Initialize your data structure here. */
    public MyHashSet() {
        data = new Node[BASE];
        for (int i = 0; i < BASE; i++) {
            data[i] = new Node();
        }
    }

    public void add(int key) {
        if (!data[key % BASE].list.contains(key)) {
            data[key % BASE].list.add(key);
        }
    }

    public void remove(int key) {
        data[key % BASE].list.removeFirstOccurrence(key);
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return data[key % BASE].list.contains(key);
    }
}

class Node {
    LinkedList<Integer> list = new LinkedList<>();
}
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
// @lc code=end
