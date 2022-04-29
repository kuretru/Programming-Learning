import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;


public class Solution {
    /**
     * lfu design
     *
     * @param operators int整型二维数组 ops
     * @param k         int整型 the k
     * @return int整型一维数组
     */
    public int[] LFU(int[][] operators, int k) {
        LFUCache<Integer, Integer> cache = new LFUCache<>(k);
        List<Integer> result = new ArrayList<>();
        for (int[] operator : operators) {
            if (operator[0] == 1) {
                cache.set(operator[1], operator[2]);
            } else {
                Integer value = cache.get(operator[1]);
                result.add(value == null ? -1 : value);
            }
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}

class CacheNode<K, V> {
    CacheNode<K, V> prev;
    CacheNode<K, V> next;
    K key;
    V value;
    int frequency;

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

    void erase() {
        CacheNode<K, V> leastUsed = tail.prev;
        tail.prev = leastUsed.prev;
        leastUsed.prev.next = tail;
        data.remove(leastUsed.key);
        this.count--;
    }

    abstract void use(CacheNode<K, V> node);

    abstract void insert(K key, V value);
}

class LFUCache<K, V> extends BaseCache<K, V> {
    public LFUCache(int capacity) {
        super(capacity);
    }

    @Override
    void use(CacheNode<K, V> node) {
        node.frequency++;
        CacheNode<K, V> root = node.prev;
        while (root != head && root.frequency <= node.frequency) {
            root = root.prev;
        }
        if (root == node.prev) {
            return;
        }

        node.prev.next = node.next;
        node.next.prev = node.prev;

        node.next = root.next;
        node.next.prev = node;
        root.next = node;
        node.prev = root;
    }

    @Override
    void insert(K key, V value) {
        while (this.count >= this.capacity) {
            erase();
        }
        CacheNode<K, V> root = tail.prev;
        while (root != head && root.frequency <= 0) {
            root = root.prev;
        }

        CacheNode<K, V> record = new CacheNode<>(root, root.next, key, value);
        data.put(key, record);
        root.next.prev = record;
        root.next = record;
        this.count++;
    }
}
