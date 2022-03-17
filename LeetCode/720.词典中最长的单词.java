/*
 * @lc app=leetcode.cn id=720 lang=java
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
    private void solve(List<String> result, Node root, char[] text, int index) {
        boolean haveChildren = false;
        for (Node child : root.children) {
            if (child == null || !child.have) {
                continue;
            }
            text[index] = child.c;
            solve(result, child, text, index + 1);
            haveChildren = true;
        }
        if (!haveChildren) {
            result.add(new String(text, 0, index));
        }
    }

    public String longestWord(String[] words) {
        Node root = new Node(' ', true);
        for (String word : words) {
            char[] data = word.toCharArray();
            Node tmp = root;
            for (int i = 0; i < data.length; i++) {
                int key = data[i] - 'a';
                if (tmp.children[key] == null) {
                    tmp.children[key] = new Node(data[i], false);
                }
                if (i + 1 == data.length) {
                    tmp.children[key].have = true;
                }
                tmp = tmp.children[key];
            }
        }

        List<String> texts = new ArrayList<>();
        solve(texts, root, new char[30], 0);
        int max = 0;
        String result = "";
        for (String text : texts) {
            if (text.length() > max) {
                max = text.length();
                result = text;
            } else if (text.length() == max && text.compareTo(result) < 0) {
                result = text;
            }
        }
        return result;
    }

    private static class Node {
        private char c;
        private boolean have;
        private Node[] children;

        public Node(char c, boolean have) {
            this.c = c;
            this.have = have;
            this.children = new Node[26];
        }
    }
}
// @lc code=end
