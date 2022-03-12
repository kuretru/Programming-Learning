/*
 * @lc app=leetcode.cn id=590 lang=java
 *
 * [590] N 叉树的后序遍历
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
    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();
        Deque<Node> stack1 = new LinkedList<>();
        Deque<Node> stack2 = new LinkedList<>();
        if (root != null) {
            stack1.push(root);
        }
        while (!stack1.isEmpty()) {
            Node top = stack1.pop();
            if (top.children.isEmpty()) {
                result.add(top.val);
            } else if (top == stack2.peek()) {
                // 说明已经添加过children
                result.add(top.val);
                stack2.pop();
            } else {
                // 添加children的同时把自己再次入栈
                stack1.push(top);
                stack2.push(top);
                for (int i = top.children.size() - 1; i >= 0; i--) {
                    stack1.push(top.children.get(i));
                }
            }
        }
        return result;
    }
}
// @lc code=end
