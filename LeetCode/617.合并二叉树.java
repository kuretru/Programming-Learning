/*
 * @lc app=leetcode.cn id=617 lang=java
 *
 * [617] 合并二叉树
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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        t1 = addFakeRoot(t1);
        t2 = addFakeRoot(t2);
        TreeNode result = addFakeRoot(null);
        mergeNode(t1, t2, result);
        return result.left;
    }

    private TreeNode addFakeRoot(TreeNode root) {
        TreeNode result = new TreeNode(0);
        result.left = root;
        return result;
    }

    private void mergeNode(TreeNode t1, TreeNode t2, TreeNode target) {
        if (t1.left != null && t2.left != null) {
            target.left = new TreeNode(t1.left.val + t2.left.val);
            mergeNode(t1.left, t2.left, target.left);
        } else if (t1.left != null && t2.left == null) {
            target.left = t1.left;
        } else if (t1.left == null && t2.left != null) {
            target.left = t2.left;
        }

        if (t1.right != null && t2.right != null) {
            target.right = new TreeNode(t1.right.val + t2.right.val);
            mergeNode(t1.right, t2.right, target.right);
        } else if (t1.right != null && t2.right == null) {
            target.right = t1.right;
        } else if (t1.right == null && t2.right != null) {
            target.right = t2.right;
        }
    }
}
// @lc code=end
