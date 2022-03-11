/*
 * @lc app=leetcode.cn id=2049 lang=java
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    private int solve(FakeNode[] nodes, int root) {
        if (root == -1) {
            return 0;
        }
        nodes[root].leftCount = solve(nodes, nodes[root].left);
        nodes[root].rightCount = solve(nodes, nodes[root].right);
        return nodes[root].leftCount + nodes[root].rightCount + 1;
    }

    public int countHighestScoreNodes(int[] parents) {
        FakeNode[] nodes = new FakeNode[parents.length];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new FakeNode();
        }
        for (int i = 1; i < parents.length; i++) {
            if (nodes[parents[i]].left == -1) {
                nodes[parents[i]].left = i;
            } else {
                nodes[parents[i]].right = i;
            }
        }

        solve(nodes, 0);

        List<Long> result = new ArrayList<>(parents.length);
        for (int i = 0; i < parents.length; i++) {
            long count = 1;
            int parentCount = parents.length - 1 - nodes[i].leftCount - nodes[i].rightCount;
            count *= parentCount > 0 ? parentCount : 1;
            count *= nodes[i].leftCount > 0 ? nodes[i].leftCount : 1;
            count *= nodes[i].rightCount > 0 ? nodes[i].rightCount : 1;
            result.add(count);
        }
        long max = Collections.max(result);
        return (int)result.stream().filter(n -> n == max).count();
    }

    static class FakeNode {
        private int left = -1;
        private int right = -1;
        private int leftCount = 0;
        private int rightCount = 0;
    }
}
// @lc code=end
