import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

// @lc code=start
class Solution {
    public int numWays(int n, int[][] relation, int k) {
        List<List<Integer>> edges = Stream.generate(ArrayList<Integer>::new).limit(n).collect(Collectors.toList());
        for (int[] r : relation) {
            edges.get(r[0]).add(r[1]);
        }
        return dfs(edges, 0, 0, k);
    }

    private int dfs(List<List<Integer>> edges, int index, int step, int k) {
        if (step == k) {
            return index == edges.size() - 1 ? 1 : 0;
        }
        int result = 0;
        for (int next : edges.get(index)) {
            result += dfs(edges, next, step + 1, k);
        }
        return result;
    }
}
// @lc code=end
