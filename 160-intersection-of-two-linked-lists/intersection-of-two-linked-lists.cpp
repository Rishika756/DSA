/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getlistlength(ListNode *head){
        int length = 0;
        while(head){
            length++;
            head = head->next;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = getlistlength(headA);
        int lenb = getlistlength(headB);
        while(lena > lenb){
            lena--;
            headA = headA->next;
        }
        while(lenb > lena){
            lenb--;
            headB = headB->next;
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};