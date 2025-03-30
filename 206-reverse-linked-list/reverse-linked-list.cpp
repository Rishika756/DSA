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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* PreNode = NULL;
        ListNode* CurrentNode = head;
        while(CurrentNode != NULL){
            ListNode* NextNode = CurrentNode->next;
            CurrentNode->next = PreNode;
            PreNode = CurrentNode;
            CurrentNode = NextNode;
        }
        head = PreNode;
        return head;
    }
};