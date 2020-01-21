/*
 * @lc app=leetcode.cn id=543 lang=java
 *
 * [543] 二叉树的直径
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

    int result = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        inorderTraversal(root);
        return result;
    }

    private int inorderTraversal(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = inorderTraversal(root.left);
        int right = inorderTraversal(root.right);
        result = Math.max(result, left + right);
        return Math.max(left, right) + 1;
    }
}
// @lc code=end
