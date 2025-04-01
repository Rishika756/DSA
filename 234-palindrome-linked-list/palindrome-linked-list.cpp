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
ListNode *reverseList(ListNode *head){
ListNode *prev = NULL ;
ListNode *curr = head ;
ListNode *next = NULL;
while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
 return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast!=NULL){
            slow = slow->next;
        }
        fast = head ; 
        slow = reverseList(slow);

        while(slow!=NULL){
            if(fast->val != slow->val){
                return false;
            }
                fast = fast->next;
                slow = slow->next;
            
           
        }
        return true;
    }
};