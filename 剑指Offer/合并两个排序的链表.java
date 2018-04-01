/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode Merge(ListNode list1,ListNode list2) {
        if (list1 == null){
            return list2;
        }
        if (list2 == null){
            return list1;
        }

        ListNode prev = null;
        ListNode root = list1.val < list2.val ? list1 : list2;
        while (list1 != null && list2 != null){
            if (list1.val < list2.val){
                if (prev == null){
                    prev = list1;
                }else{
                    prev.next = list1;
                    prev = list1;
                }
                list1 = list1.next;
            }else{
                if (prev == null){
                    prev = list2;
                }else{
                    prev.next = list2;
                    prev = list2;
                }
                list2 = list2.next;
            }
        }
        while (list1 != null){
            prev.next = list1;
            prev = list1;
            list1 = list1.next;
        }
        while (list2 != null){
            prev.next = list2;
            prev = list2;
            list2 = list2.next;
        }

        return root;
    }
}
