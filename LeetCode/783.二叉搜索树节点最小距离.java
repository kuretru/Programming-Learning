/*
 * @lc app=leetcode.cn id=783 lang=java
 *
 * [783] 二叉搜索树节点最小距离
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
    private int lastValue;
    private int minDistance;

    public int minDiffInBST(TreeNode root) {
        lastValue = -1;
        minDistance = Integer.MAX_VALUE;
        preOrderTravel(root);
        return minDistance;
    }

    private void preOrderTravel(TreeNode root) {
        if (root.left != null) {
            preOrderTravel(root.left);
        }
        if (lastValue != -1) {
            minDistance = Math.min(minDistance, root.val - lastValue);
        }
        lastValue = root.val;
        if (root.right != null) {
            preOrderTravel(root.right);
        }
    }
}
// @lc code=end
