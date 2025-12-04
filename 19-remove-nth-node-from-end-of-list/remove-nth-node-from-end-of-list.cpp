/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head ==NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* firstptr = dummy;
        ListNode* secondptr = dummy;
        for(int i = 0 ; i<n ; i++){
            secondptr = secondptr->next;
        }
        while(secondptr->next != NULL){
            firstptr = firstptr->next;
            secondptr = secondptr->next;
        }
        firstptr->next = firstptr->next->next;
        ListNode* newhead = dummy->next;
        delete dummy;

        return newhead;
    }
};