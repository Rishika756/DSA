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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        k = k % len;
        int numOfSteps_To_newHead = len - k;

        ListNode* newtail = head;
        for (int i = 1; i < numOfSteps_To_newHead; i++) {
            newtail = newtail->next;
        }

        head = newtail->next;
        newtail->next = nullptr;

        return head;
    }
};