/*
 * @lc app=leetcode.cn id=206 lang=java
 *
 * [206] 反转链表
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
    public ListNode reverseList(ListNode head) {
        ListNode result = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = result;
            result = head;
            head = next;
        }
        return result;
    }
}
// @lc code=end
