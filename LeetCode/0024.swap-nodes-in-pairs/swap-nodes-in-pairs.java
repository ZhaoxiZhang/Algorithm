/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)   return head;

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode first = null;
        ListNode second = null;
        ListNode tmp = null;
        while (head != null && head.next != null){
            first = head;
            second = head.next;
            tmp = second.next;
            
            second.next = first;
            prev.next = second;
            
            prev = first;
            first.next = tmp;
            
            head = tmp;
        }
        
        return dummy.next;
    }
}