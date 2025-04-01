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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int cnt = 0;
        while (cnt < k) {
            if (temp == NULL) {
                return head; 
            }
            temp = temp->next;
            cnt++;
        }
        ListNode *prev = NULL, *curr = head, *next = NULL;
        cnt = 0;
        while (cnt < k && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};