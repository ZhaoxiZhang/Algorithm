/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null)   return null;
        boolean flag = false;
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast){
                flag = true;
                break;
            }
        }
        if (flag){
            fast = head;
            while(fast != slow){
                fast = fast.next;
                slow = slow.next;
            }
            return slow;
        }
        return null;
    }
}