/*
 * @lc app=leetcode.cn id=1305 lang=java
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> data1 = new ArrayList<>();
        List<Integer> data2 = new ArrayList<>();
        inorderTravel(data1, root1);
        inorderTravel(data2, root2);
        return merge(data1, data2);
    }

    private void inorderTravel(List<Integer> result, TreeNode node) {
        if (node == null) {
            return;
        }
        inorderTravel(result, node.left);
        result.add(node.val);
        inorderTravel(result, node.right);
    }

    private List<Integer> merge(List<Integer> data1, List<Integer> data2) {
        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        while (i < data1.size() && j < data2.size()) {
            if (data1.get(i) < data2.get(j)) {
                result.add(data1.get(i++));
            } else {
                result.add(data2.get(j++));
            }
        }
        if (i < data1.size()) {
            result.addAll(data1.subList(i, data1.size()));
        }
        if (j < data2.size()) {
            result.addAll(data2.subList(j, data2.size()));
        }
        return result;
    }
}
// @lc code=end
