import java.util.HashSet;
import java.util.Set;

// @lc code=start
class Solution {

    public static void main(String[] args) {
        new Solution().permutation("abcd");
    }

    public String[] permutation(String s) {
        Set<String> result = new HashSet<>();
        char[] chars = s.toCharArray();
        solve(result, chars, 0);
        return result.toArray(new String[0]);
    }

    private void solve(Set<String> result, char[] chars, int index) {
        if (index + 1 == chars.length) {
            result.add(new String(chars));
            return;
        }
        for (int i = index; i < chars.length; i++) {
            swap(chars, index, i);
            solve(result, chars, index + 1);
            swap(chars, index, i);
        }
    }

    private void swap(char[] chars, int x, int y) {
        char tmp = chars[x];
        chars[x] = chars[y];
        chars[y] = tmp;
    }

}
// @lc code=end
