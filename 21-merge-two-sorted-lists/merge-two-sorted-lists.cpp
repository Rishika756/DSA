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
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        ListNode* dummy = new ListNode(-1); 
        ListNode* returnnode = dummy;
        while(L1 != NULL && L2!=NULL){
            if(L1->val <= L2->val){
                returnnode->next =  L1;
                L1 = L1->next;
            }else{
                returnnode->next = L2;
                L2 = L2->next;
            }
            returnnode = returnnode->next;
        }
        if(L1 == NULL){
            returnnode->next = L2;
        }
        else if(L2 == NULL){
            returnnode->next = L1;
        }
        ListNode* head = dummy->next;
        delete dummy; 
        return head;
        
    }
};