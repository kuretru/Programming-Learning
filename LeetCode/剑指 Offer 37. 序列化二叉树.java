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
public class Codec {
    private static final String NULL = "null";

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "[]";
        }
        List<String> nodes = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode peek = queue.poll();
            if (peek == null) {
                nodes.add(NULL);
                continue;
            } else {
                nodes.add(String.valueOf(peek.val));
            }
            queue.add(peek.left);
            queue.add(peek.right);
        }
        while (NULL.equals(nodes.get(nodes.size() - 1))) {
            nodes.remove(nodes.size() - 1);
        }
        String data = String.join(",", nodes);
        return "[" + data + "]";
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if ("[]".equals(data)) {
            return null;
        }
        data = "null," + data.substring(1, data.length() - 1);
        String[] nodes = data.split(",");
        int index = 0;
        TreeNode root = new TreeNode(-1);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (index < nodes.length) {
            TreeNode peek = queue.poll();
            String a = nodes[index++];
            String b = index < nodes.length ? nodes[index++] : NULL;
            if (!NULL.equals(a)) {
                TreeNode left = new TreeNode(Integer.parseInt(a));
                peek.left = left;
                queue.add(left);
            }
            if (!NULL.equals(b)) {
                TreeNode right = new TreeNode(Integer.parseInt(b));
                peek.right = right;
                queue.add(right);
            }
        }
        return root.right;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
// @lc code=end
