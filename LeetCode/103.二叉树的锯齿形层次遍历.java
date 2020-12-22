import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=103 lang=java
 *
 * [103] 二叉树的锯齿形层次遍历
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        preorderTraversal(result, root, 0);
        return result;
    }

    private void preorderTraversal(List<List<Integer>> result, TreeNode root, int level) {
        if (root == null) {
            return;
        }
        if (result.size() == level) {
            result.add(new ArrayList<>());
        }
        if (level % 2 == 1) {
            result.get(level).add(root.val);
        } else {
            result.get(level).add(0, root.val);
        }
        preorderTraversal(result, root.left, level + 1);
        preorderTraversal(result, root.right, level + 1);
    }
}
// @lc code=end
