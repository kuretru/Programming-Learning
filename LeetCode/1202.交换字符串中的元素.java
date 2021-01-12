import java.util.*;

/*
 * @lc app=leetcode.cn id=1202 lang=java
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        char[] text = s.toCharArray();

        DisjointSet disjointSet = new DisjointSet(text.length);
        for (List<Integer> pair : pairs) {
            int rootX = disjointSet.find(pair.get(0));
            int rootY = disjointSet.find(pair.get(1));
            if (rootX != rootY) {
                disjointSet.union(rootX, rootY);
            }
        }

        Map<Integer, List<Integer>> sets = disjointSet.getSets();
        for (List<Integer> indexes : sets.values()) {
            char[] chars = new char[indexes.size()];
            for (int i = 0; i < indexes.size(); i++) {
                chars[i] = text[indexes.get(i)];
            }
            Arrays.sort(chars);
            for (int i = 0; i < indexes.size(); i++) {
                text[indexes.get(i)] = chars[i];
            }
        }

        return new String(text);
    }
}

class DisjointSet {
    private final int[] data;

    public DisjointSet(int size) {
        data = new int[size];
        Arrays.fill(data, -1);
    }

    public int find(int index) {
        if (data[index] < 0) {
            return index;
        }
        int root = find(data[index]);
        data[index] = root;
        return root;
    }

    public int union(int rootX, int rootY) {
        if (rootX == rootY) {
            return rootX;
        }
        if (data[rootX] > data[rootY]) {
            data[rootY] += data[rootX];
            data[rootX] = rootY;
            return rootY;
        } else {
            data[rootX] += data[rootY];
            data[rootY] = rootX;
            return rootX;
        }
    }

    public Map<Integer, List<Integer>> getSets() {
        Map<Integer, List<Integer>> result = new HashMap<>(16);
        for (int i = 0; i < data.length; i++) {
            int root = find(i);
            List<Integer> list = result.computeIfAbsent(root, k -> new ArrayList<>());
            list.add(i);
        }
        return result;
    }
}
// @lc code=end
