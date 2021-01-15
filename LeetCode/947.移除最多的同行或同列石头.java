import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=947 lang=java
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution {
    private static final int MAX_INDEX = 10001;

    public int removeStones(int[][] stones) {
        DisjointSet disjointSet = new DisjointSet(MAX_INDEX << 1);
        for (int[] stone : stones) {
            int rootX = disjointSet.find(stone[0]);
            int rootY = disjointSet.find(stone[1] + MAX_INDEX);
            disjointSet.union(rootX, rootY);
        }
        int setsCount = disjointSet.getSetsCount();
        return stones.length - setsCount;
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

    public int getSetsCount() {
        int result = 0;
        for (int root : data) {
            if (root < -1) {
                result++;
            }
        }
        return result;
    }
}
// @lc code=end
