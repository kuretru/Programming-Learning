import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层次遍历
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        preorderTraversal(result, root, 1);
        return result;
    }

    private void preorderTraversal(List<List<Integer>> result, TreeNode root, int level) {
        if (root == null) {
            return;
        }
        if (result.size() < level) {
            result.add(new ArrayList<>());
        }
        result.get(level - 1).add(root.val);
        preorderTraversal(result, root.left, level + 1);
        preorderTraversal(result, root.right, level + 1);
    }
}
// @lc code=end
