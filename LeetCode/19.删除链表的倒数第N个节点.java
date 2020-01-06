/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fakeHead = new ListNode(-1);
        fakeHead.next = head;
        ListNode target = fakeHead;
        while (head != null) {
            head = head.next;
            if (n-- <= 0) {
                target = target.next;
            }
        }
        target.next = target.next.next;
        return fakeHead.next;
    }
}
// @lc code=end
