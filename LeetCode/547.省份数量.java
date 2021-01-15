import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=547 lang=java
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
    public int findCircleNum(int[][] isConnected) {
        DisjointSet set = new DisjointSet(isConnected.length);
        for (int i = 0; i < isConnected.length; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j) {
                    continue;
                }
                if (isConnected[i][j] == 1) {
                    int rootX = set.find(i);
                    int rootY = set.find(j);
                    if (rootX != rootY) {
                        set.union(rootX, rootY);
                    }
                }
            }
        }
        return set.getRootCount();
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
        if (rootX > rootY) {
            data[rootY] += data[rootX];
            data[rootX] = rootY;
            return rootY;
        } else {
            data[rootX] += data[rootY];
            data[rootY] = rootX;
            return rootX;
        }
    }

    public int getRootCount() {
        int result = 0;
        for (int root : data) {
            if (root < 0) {
                result++;
            }
        }
        return result;
    }

    public int[] getData() {
        return data;
    }
}
// @lc code=end
