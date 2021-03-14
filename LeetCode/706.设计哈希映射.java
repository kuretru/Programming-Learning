import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=706 lang=java
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap {
    private static final int BASE = 997;
    private final Node[] data;

    /** Initialize your data structure here. */
    public MyHashMap() {
        data = new Node[BASE];
        for (int i = 0; i < BASE; i++) {
            data[i] = new Node();
        }
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        for (Pair p : data[key % BASE].list) {
            if (p.key == key) {
                p.value = value;
                return;
            }
        }
        data[key % BASE].list.add(new Pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        for (Pair p : data[key % BASE].list) {
            if (p.key == key) {
                return p.value;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        for (Pair p : data[key % BASE].list) {
            if (p.key == key) {
                data[key % BASE].list.remove(p);
                return;
            }
        }
    }
}

class Node {
    LinkedList<Pair> list = new LinkedList<>();
}

class Pair {
    int key;
    int value;

    public Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
// @lc code=end
