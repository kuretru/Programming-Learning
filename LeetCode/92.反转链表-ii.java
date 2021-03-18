/*
 * @lc app=leetcode.cn id=92 lang=java
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode result = new ListNode(0, head);
        ListNode previousOfLeft = result;
        for (int i = 1; i < left; i++) {
            previousOfLeft = previousOfLeft.next;
        }
        head = previousOfLeft.next;
        for (int i = left; i < right; i++) {
            ListNode next = head.next;
            head.next = next.next;
            next.next = previousOfLeft.next;
            previousOfLeft.next = next;
        }
        return result.next;
    }
}
// @lc code=end
