/*
 * @lc app=leetcode.cn id=208 lang=java
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
    private final Trie[] children;
    private boolean end;

    /** Initialize your data structure here. */
    public Trie() {
        children = new Trie[26];
        end = false;
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie head = find(word, false);
        head.end = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie head = find(word, true);
        return head != null && head.end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie head = find(prefix, true);
        return head != null;
    }

    private Trie find(String word, boolean searchMode) {
        Trie head = this;
        char[] chars = word.toCharArray();
        for (char c : chars) {
            int index = c - 'a';
            if (head.children[index] == null) {
                if (searchMode) {
                    return null;
                } else {
                    head.children[index] = new Trie();
                }
            }
            head = head.children[index];
        }
        return head;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end
