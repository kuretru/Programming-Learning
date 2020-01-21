/*
 * @lc app=leetcode.cn id=101 lang=java
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    private boolean isMirror(TreeNode x, TreeNode y) {
        if (x == null && y == null) {
            return true;
        } else if (x == null || y == null) {
            return false;
        } else if (x.val != y.val) {
            return false;
        }
        return isMirror(x.left, y.right) && isMirror(x.right, y.left);
    }
}
// @lc code=end
