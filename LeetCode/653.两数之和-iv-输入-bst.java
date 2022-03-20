/*
 * @lc app=leetcode.cn id=653 lang=java
 *
 * [653] 两数之和 IV - 输入 BST
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
    private void inorderTravel(List<Integer> orderedData, TreeNode root) {
        if (root == null) {
            return;
        }
        inorderTravel(orderedData, root.left);
        orderedData.add(root.val);
        inorderTravel(orderedData, root.right);
    }

    public boolean findTarget(TreeNode root, int k) {
        List<Integer> orderedData = new ArrayList<>();
        inorderTravel(orderedData, root);
        for (int i = 0, j = orderedData.size() - 1; i < j; ) {
            if (orderedData.get(i) + orderedData.get(j) < k) {
                i++;
            } else if (orderedData.get(i) + orderedData.get(j) > k) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
}
// @lc code=end
