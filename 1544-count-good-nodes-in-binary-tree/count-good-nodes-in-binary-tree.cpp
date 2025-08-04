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
int countnodes(TreeNode *node , int maxval){
    if(!node) return 0;
    int count = 0;
    if(node->val >= maxval){
        maxval = node->val;
        count  = 1;
    }
    count += countnodes(node->left , maxval);
    count += countnodes(node->right  , maxval);
    return count;
}
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return countnodes(root , root->val);
    }
};