/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer>pque = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1.compareTo(o2);
            }
        });
        ListNode current = null;
        for (int i = 0;i < lists.length;i++){
            current = lists[i];
            while (current != null){
                pque.add(current.val);
                current = current.next;
            }
        }
        ListNode head = null;
        for (int i = 0;i < lists.length;i++){
            if (lists[i] != null && lists[i].val == pque.peek()){
                head = lists[i];
                break;
            }
        }
        ListNode prev = null;
        while(!pque.isEmpty()){
            int val = pque.poll();
            for (int i = 0;i < lists.length;i++){
                if (lists[i] == null)   continue;
                if (lists[i].val == val){
                    if (prev == null){
                        prev = lists[i];
                    }else{
                        prev.next = lists[i];
                        prev = lists[i];
                    }
                    lists[i] = lists[i].next;
                }
            }
        }
        return head;
    }
}