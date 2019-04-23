/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode head = l1.val < l2.val ? l1 : l2;
        ListNode prev = null;
        while (l1 != null && l2 != null){
            if (l1.val < l2.val){
                if (prev == null){
                    prev = l1;
                }else{
                    prev.next = l1;
                    prev = l1;
                }
                l1 = l1.next;
            }else{
                if (prev == null){
                    prev = l2;
                }else{
                    prev.next = l2;
                    prev = l2;
                }
                l2 = l2.next;
            }
        }

        while (l1 != null){
            prev.next = l1;
            prev = l1;
            l1 = l1.next;
        }
        while (l2 != null){
            prev.next = l2;
            prev = l2;
            l2 = l2.next;
        }
        return head;
    }
}