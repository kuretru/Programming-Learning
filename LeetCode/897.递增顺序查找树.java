/*
 * @lc app=leetcode.cn id=897 lang=java
 *
 * [897] 递增顺序查找树
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
    private TreeNode lastNode;

    public TreeNode increasingBST(TreeNode root) {
        TreeNode headNode = new TreeNode();
        lastNode = headNode;
        inorderTraversal(root);
        return headNode.right;
    }

    private void inorderTraversal(TreeNode root) {
        if (root.left != null) {
            inorderTraversal(root.left);
        }
        lastNode.right = root;
        root.left = null;
        lastNode = root;
        if (root.right != null) {
            inorderTraversal(root.right);
        }
    }
}
// @lc code=end
