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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = head;
        while (head != NULL){
            ListNode* dummy = head;
            int tmpK = k;
            stack<int>stk;
            while (tmpK && dummy != NULL){
                stk.push(dummy->val);
                dummy = dummy->next;
                tmpK--;
            }

            if (!tmpK){
                while (!stk.empty()){
                    int val = stk.top();
                    stk.pop();
                    head->val = val;
                    head = head->next;
                }
            }else   break;
        }
        return res;
    }
};