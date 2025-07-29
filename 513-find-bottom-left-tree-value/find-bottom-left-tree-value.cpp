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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*>q;
        vector<TreeNode*>ans;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            ans.push_back(curr);

            if(curr->right){
                q.push(curr->right);
            }
            if(curr->left){
                q.push(curr->left);
            }
        }
        int result = ans.back()->val;
        return result;
    }
};