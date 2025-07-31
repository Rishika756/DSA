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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalIndices;
        int index = 1;  
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr && curr->next) {
            int nextVal = curr->next->val;
            if ((curr->val > prev->val && curr->val > nextVal) ||
                (curr->val < prev->val && curr->val < nextVal)) {
                criticalIndices.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        if (criticalIndices.size() < 2) {
            return {-1, -1};  
        }
        int minDist = INT_MAX;
        for (int i = 1; i < criticalIndices.size(); i++) {
            minDist = min(minDist, criticalIndices[i] - criticalIndices[i-1]);
        }
        int maxDist = criticalIndices.back() - criticalIndices.front();
        return {minDist, maxDist};
    }
};
