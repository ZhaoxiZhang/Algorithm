/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        ListNode p = head,q = head;
        while (p != null && --k != 0){
            p = p.next;
        }
        if (p == null)    return null;
        while (p.next != null){
            p = p.next;
            q = q.next;
        }
        return q;
    }
}