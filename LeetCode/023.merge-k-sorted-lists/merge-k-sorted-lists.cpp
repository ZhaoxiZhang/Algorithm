/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == NULL) return pHead2;
        if (pHead2 == NULL) return pHead1;
        ListNode *prev = NULL;
        ListNode *root = pHead1->val < pHead2->val ? pHead1 : pHead2;
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1->val < pHead2->val) {
                if (prev == NULL) {
                    prev = pHead1;
                } else {
                    prev->next = pHead1;
                    prev = pHead1;
                }
                pHead1 = pHead1->next;
            } else {
                if (prev == NULL) {
                    prev = pHead2;
                } else {
                    prev->next = pHead2;
                    prev = pHead2;
                }
                pHead2 = pHead2->next;
            }
        }

        while (pHead1 != NULL) {
            prev->next = pHead1;
            prev = pHead1;
            pHead1 = pHead1->next;
        }
        while (pHead2 != NULL) {
            prev->next = pHead2;
            prev = pHead2;
            pHead2 = pHead2->next;
        }
        return root;
    }

    ListNode *mergeKListsInternal(vector<ListNode *> &lists, int size) {
        if (size == 0)  return NULL;
        if (size == 1)  return lists[0];
        int mid = (size + 1) >> 1;
        for (int i = mid; i < size; i++) {
            lists[i - mid] = Merge(lists[i - mid], lists[i]);
        }
        
        return mergeKListsInternal(lists, mid);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKListsInternal(lists, lists.size());
    }
};