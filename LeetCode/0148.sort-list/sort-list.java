/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)  return head;
        
        ListNode slow = head,fast = head;
        ListNode prev = null;
        while (fast != null && fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = null;
        
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(slow);
        return merge(l1,l2);
    }

    public ListNode merge(ListNode p1,ListNode p2){
        ListNode dummy = new ListNode(0),head = dummy;
        while (p1 != null && p2 != null){
            if (p1.val < p2.val){
                head.next = p1;
                p1 = p1.next;
            }else{
                head.next = p2;
                p2 = p2.next;
            }
            head = head.next;
        }
        if (p1 != null){
            head.next = p1;
        }
        if (p2 != null){
            head.next = p2;
        }
        return dummy.next;
    }
}