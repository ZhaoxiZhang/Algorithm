/**
*    public class ListNode {
*        int val;
*        ListNode next = null;
*
*        ListNode(int val) {
*            this.val = val;
*        }
*    }
*
*/
import java.util.*;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer>res = new ArrayList<>();
        while (listNode != null){
            res.add(listNode.val);
            listNode = listNode.next;
        }
        Collections.reverse(res);
        return res;
    }
}