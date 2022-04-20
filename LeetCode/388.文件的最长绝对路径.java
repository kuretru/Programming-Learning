/*
 * @lc app=leetcode.cn id=388 lang=java
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
    public int lengthLongestPath(String input) {
        String[] lines = input.split("\n");
        Deque<Integer> stack = new LinkedList<>();
        int currentLength = 0;
        int result = 0;
        for (String line : lines) {
            int depth = 1;
            for (int i = 0; i < line.length() && line.charAt(i) == '\t'; i++) {
                depth++;
            }
            int length = line.length() - depth + 1;

            while (stack.size() >= depth) {
                currentLength = stack.pop();
            }
            stack.push(currentLength);

            boolean isFile = line.lastIndexOf(".") != -1;
            if (isFile) {
                result = Math.max(result, currentLength + length + stack.size() - 1);
            } else {
                currentLength += length;
                stack.push(currentLength);
            }
        }
        return result;
    }
}
// @lc code=end
