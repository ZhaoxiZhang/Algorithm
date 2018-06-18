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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)	return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* first;
        ListNode* second;
        ListNode* tmp;
        while (head != NULL && head->next != NULL){
        	first = head;
        	second = head->next;
        	tmp = second->next;

        	second->next = first;
        	prev->next = second;

        	prev = first;
        	first->next = tmp;

        	head = tmp;
        }

        return dummy->next;
    }
};