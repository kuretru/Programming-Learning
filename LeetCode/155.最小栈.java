import java.util.Deque;
import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=155 lang=java
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    private final Deque<Integer> stack;
    private final Deque<Integer> minStack;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new LinkedList<>();
        minStack = new LinkedList<>();
    }

    public void push(int x) {
        stack.push(x);
        int min = minStack.isEmpty() ? Integer.MAX_VALUE : minStack.peek();
        minStack.push(Math.min(min, x));
    }

    public void pop() {
        stack.pop();
        minStack.pop();
    }

    public int top() {
        if (stack.isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return stack.peek();
    }

    public int getMin() {
        if (minStack.isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end
