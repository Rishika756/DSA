
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* reversebetween(ListNode* head , int left , int right){
        if(left == right) return head;

        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        int length = 1;
        ListNode* temp = head;

        while(temp != NULL){
            if(length == left - 1) a = temp;
            if(length == left) b = temp;
            if(length == right) c = temp;
            if(length == right + 1) d = temp;

            temp = temp->next;
            length++;
        }

        if(a != NULL) a->next = NULL;
        c->next = NULL;
        ListNode* reversed = reverseLinkedList(b);

        if(a != NULL) a->next = reversed;
        b->next = d;
        return (a != NULL) ? head : reversed;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = &dummy;
        int groupSize = 1;

        while (temp->next != NULL) {
            ListNode* groupStart = temp->next;
            ListNode* groupEnd = temp;

            int actualLength = 0;
            for (int i = 0; i < groupSize && groupEnd->next != NULL; i++) {
                groupEnd = groupEnd->next;
                actualLength++;
            }

            ListNode* nextGroupStart = groupEnd->next;
            groupEnd->next = NULL;

            if (actualLength % 2 == 0) {
                ListNode* reversed = reverseLinkedList(groupStart);
                temp->next = reversed;

                groupStart->next = nextGroupStart;
                temp = groupStart;
            } else {
                temp = groupEnd;
                groupEnd->next = nextGroupStart;
            }

            groupSize++;
        }

        return dummy.next;
    }
};
