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
        ListNode list1 = head,list2 = head;
        while(n-- != 0){
            list1 = list1.next;
        }
        while (list1 != null && list1.next != null){
            list1 = list1.next;
            list2 = list2.next;
        }
        if (list1 == null){
            return head.next;
        }else{
            list2.next = list2.next.next;
            return head;
        }
    }
}