import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=684 lang=java
 *
 * [684] 冗余连接
 */

// @lc code=start

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        DisjointSet disjointSet = new DisjointSet(edges.length + 1);
        for (int[] edge : edges) {
            int rootX = disjointSet.find(edge[0]);
            int rootY = disjointSet.find(edge[1]);
            if (rootX == rootY) {
                return edge;
            } else {
                disjointSet.union(rootX, rootY);
            }
        }
        return new int[]{0, 0};
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
}
// @lc code=end
