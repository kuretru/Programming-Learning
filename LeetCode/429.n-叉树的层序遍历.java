/*
 * @lc app=leetcode.cn id=429 lang=java
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> level = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Node firstNode = null;
        Deque<Node> queue = new LinkedList<>();
        queue.addLast(root);
        while (!queue.isEmpty()) {
            Node front = queue.removeFirst();
            if (front == firstNode) {
                firstNode = null;
                result.add(level);
                level = new ArrayList<>();
            }
            if (firstNode == null) {
                if (!front.children.isEmpty()) {
                    firstNode = front.children.get(0);
                }
            }
            level.add(front.val);
            for (Node child : front.children) {
                queue.addLast(child);
            }
        }
        result.add(level);
        return result; 
    }
}
// @lc code=end
