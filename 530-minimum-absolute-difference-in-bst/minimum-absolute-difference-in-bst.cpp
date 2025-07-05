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
    int mini = INT_MAX;
    TreeNode* prev = nullptr;
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        if(prev != nullptr){
            mini = min(mini , abs(node->val - prev->val));
        }
        prev = node;
        inorder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
       inorder(root);
       return mini;
    }
};