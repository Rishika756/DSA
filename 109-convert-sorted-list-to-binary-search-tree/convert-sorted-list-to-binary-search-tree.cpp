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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* helper(ListNode* start , ListNode*end){
    if(start == end) return NULL;
    ListNode* slow = start;
    ListNode* fast = start;
    while(fast!= end && fast->next!=end){
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *treeroot = new TreeNode(slow->val);
    treeroot->left = helper(start , slow);
    treeroot->right = helper(slow->next, end);
    return treeroot;
}
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        return helper(head , NULL);
    }
};