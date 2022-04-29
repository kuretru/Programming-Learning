import java.util.HashMap;
import java.util.Map;

public class Solution {
    private final LRUCache<Integer, Integer> cache;

    public Solution(int capacity) {
        this.cache = new LRUCache<>(capacity);
    }

    public int get(int key) {
        Integer value = this.cache.get(key);
        return value == null ? -1 : value;
    }

    public void set(int key, int value) {
        this.cache.set(key, value);
    }

}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution solution = new Solution(capacity);
 * int output = solution.get(key);
 * solution.set(key,value);
 */

class CacheNode<K, V> {

    CacheNode<K, V> prev;
    CacheNode<K, V> next;
    K key;
    V value;

    public CacheNode() {

    }

    public CacheNode(CacheNode<K, V> prev, CacheNode<K, V> next, K key, V value) {
        this.prev = prev;
        this.next = next;
        this.key = key;
        this.value = value;
    }
}

abstract class BaseCache<K, V> {
    protected final Map<K, CacheNode<K, V>> data;
    protected final CacheNode<K, V> head;
    protected final CacheNode<K, V> tail;
    protected final int capacity;
    protected int count;

    protected BaseCache(int capacity) {
        this.data = new HashMap<>((int)(capacity * 1.0 / 0.75) + 1);
        this.head = new CacheNode<>();
        this.tail = new CacheNode<>();
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.capacity = capacity;
        this.count = 0;
    }

    public V get(K key) {
        if (data.containsKey(key)) {
            CacheNode<K, V> node = data.get(key);
            use(node);
            return node.value;
        }
        return null;
    }

    public void set(K key, V value) {
        if (data.containsKey(key)) {
            CacheNode<K, V> node = data.get(key);
            node.value = value;
            use(node);
        } else {
            insert(key, value);
        }
    }

    abstract void use(CacheNode<K, V> node);

    abstract void insert(K key, V value);

    abstract void erase();
}

class LRUCache<K, V> extends BaseCache<K, V> {
    public LRUCache(int capacity) {
        super(capacity);
    }

    @Override
    void use(CacheNode<K, V> node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;

        node.next = head.next;
        node.prev = head;

        head.next.prev = node;
        head.next = node;
    }

    @Override
    void insert(K key, V value) {
        CacheNode<K, V> record = new CacheNode<>(head, head.next, key, value);
        data.put(key, record);
        head.next.prev = record;
        head.next = record;
        this.count++;
        while (this.count > this.capacity) {
            erase();
        }
    }

    @Override
    void erase() {
        CacheNode<K, V> leastUsed = tail.prev;
        tail.prev = leastUsed.prev;
        leastUsed.prev.next = tail;
        data.remove(leastUsed.key);
        this.count--;
    }
}
