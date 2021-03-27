/*
 * @lc app=leetcode.cn id=61 lang=java
 *
 * [61] 旋转链表
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        int count = 0;
        for (ListNode p = head; true; p = p.next) {
            count++;
            if (p.next == null) {
                p.next = head;
                break;
            }
        }
        int index = count - k % count;
        for (int i = 1; i < index; i++) {
            head = head.next;
        }
        ListNode result = head.next;
        head.next = null;
        return result;
    }
}
// @lc code=end
