/*
 * @lc app=leetcode.cn id=606 lang=java
 *
 * [606] 根据二叉树创建字符串
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
    private void solve(StringBuilder result, TreeNode root) {
        result.append(root.val);
        if (root.left == null && root.right == null) {
            return;
        }
        result.append('(');
        if (root.left != null) {
            solve(result, root.left);
        }
        result.append(')');
        if (root.right != null) {
            result.append('(');
            solve(result, root.right);
            result.append(')');
        }
    }

    public String tree2str(TreeNode root) {
        StringBuilder result = new StringBuilder();
        solve(result, root);
        return result.toString();
    }
}
// @lc code=end
