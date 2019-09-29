/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode head = result;
        int carry = 0;
        while (l1 != null || l2 != null || carry > 0) {
            int number = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
            ListNode node = new ListNode(number % 10);
            carry = number / 10;
            head.next = node;
            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
            head = head.next;
        }
        return result.next;
    }
}
