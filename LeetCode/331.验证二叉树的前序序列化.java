/*
 * @lc app=leetcode.cn id=331 lang=java
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
    private static final String NULL = "#";

    public boolean isValidSerialization(String preorder) {
        if (NULL.equals(preorder)) {
            return true;
        }
        String[] nodes = preorder.split(",");
        int stack = 0;
        for (int i = 0; i < nodes.length; i++) {
            if (NULL.equals(nodes[i])) {
                if (stack == 0) {
                    return false;
                }
                stack--;
            } else {
                if (stack != 0) {
                    stack--;
                } else if (i > 0) {
                    return false;
                }
                stack += 2;
            }
        }
        return stack == 0;
    }
}
// @lc code=end
