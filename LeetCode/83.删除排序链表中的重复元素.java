/*
 * @lc app=leetcode.cn id=83 lang=java
 *
 * [83] 删除排序链表中的重复元素
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode result = new ListNode(-1, null);
        ListNode p = result;
        while (head != null) {
            ListNode q;
            for (q = head.next; q != null; q = q.next) {
                if (head.val != q.val) {
                    break;
                }
            }
            p.next = head;
            p = p.next;
            head = q;
        }
        p.next = null;
        return result.next;
    }
}
// @lc code=end
