/*
 * @lc app=leetcode.cn id=933 lang=java
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
    private final Deque<Integer> data;

    public RecentCounter() {
        this.data = new LinkedList<>();
    }

    public int ping(int t) {
        int begin = t - 3000;
        data.addLast(t);
        while (data.getFirst() < begin) {
            data.removeFirst();
        }
        return data.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
// @lc code=end
