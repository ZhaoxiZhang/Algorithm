/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list = NULL;
        ListNode *current,*prev;
        int carry = 0,sum = 0;
        while(l1 && l2){
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;

            current = new ListNode(0);

            if (list == NULL){
                list = current;
            }else{
                prev->next = current;
            }
            current->val = sum;
            current->next = NULL;
            prev = current;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1){
            current = new ListNode(0);
            current->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            current->next = NULL;
            prev->next = current;
            prev = current;

            l1 = l1->next;
        }


        while (l2){
            current = new ListNode(0);
            current->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            current->next = NULL;
            prev->next = current;
            prev = current;

            l2 = l2->next;
        }
        if (carry){
            current = new ListNode(0);
            current->val = carry;
            current->next = NULL;
            prev->next = current;
        }
        return list;
    }
};