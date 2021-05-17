/*
 * @lc app=leetcode.cn id=993 lang=java
 *
 * [993] 二叉树的堂兄弟节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        int[] parents = new int[101];
        int[] depth = new int[101];
        preorderTravel(root, parents, depth, 0, 1);
        return depth[x] == depth[y] && depth[x] != 0 && parents[x] != parents[y];
    }

    private void preorderTravel(TreeNode root, int[] parents, int[] depth, int parent, int level) {
        if (root == null) {
            return;
        }
        parents[root.val] = parent;
        depth[root.val] = level;
        preorderTravel(root.left, parents, depth, root.val, level + 1);
        preorderTravel(root.right, parents, depth, root.val, level + 1);
    }
}
// @lc code=end
