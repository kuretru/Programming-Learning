/*
 * @lc app=leetcode.cn id=341 lang=java
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private final Deque<Iterator<NestedInteger>> iterators;

    public NestedIterator(List<NestedInteger> nestedList) {
        iterators = new LinkedList<>();
        iterators.push(nestedList.iterator());
    }

    @Override
    public Integer next() {
        return iterators.peek().next().getInteger();
    }

    @Override
    public boolean hasNext() {
        while (!iterators.isEmpty()) {
            if (!iterators.peek().hasNext()) {
                iterators.pop();
                continue;
            }
            NestedInteger next = iterators.peek().next();
            if (next.isInteger()) {
                List<NestedInteger> list = new ArrayList<>();
                list.add(next);
                iterators.push(list.iterator());
                return true;
            }
            iterators.push(next.getList().iterator());
        }
        return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
// @lc code=end
