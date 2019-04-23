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
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        ListNode prev = new ListNode(0);
        ListNode dummy = prev;

        int carray = 0;
        int sum = 0;
        while (l1 != null && l2 != null){
            sum = l1.val + l2.val + carray;

            ListNode current = new ListNode(sum % 10);
            carray = sum / 10;

            prev.next = current;
            prev = current;
            l1 = l1.next;
            l2 = l2.next;
        }

        ListNode tmp = l1 == null ? l2 : l1;
        while (tmp != null){
            sum = tmp.val + carray;

            ListNode current = new ListNode(sum % 10);
            carray = sum / 10;

            prev.next = current;
            prev = current;
            tmp = tmp.next;
        }

        if (carray != 0){
            ListNode current = new ListNode(carray);
            prev.next = current;
        }

        return dummy.next;
    }
}