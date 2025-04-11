class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *leftpre = dummy;
        for (int i = 0; i < left - 1; i++) {
            leftpre = leftpre->next;
        }

        ListNode *currnode = leftpre->next;
        ListNode* prenode = nullptr;

        for (int i = 0; i <= right - left; i++) {
            ListNode* nextnode = currnode->next;
            currnode->next = prenode;
            prenode = currnode;
            currnode = nextnode;
        }

        leftpre->next->next = currnode;  
        leftpre->next = prenode;         

        return dummy->next;
    }
};