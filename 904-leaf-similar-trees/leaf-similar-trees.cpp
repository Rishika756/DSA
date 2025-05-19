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
void inorder(TreeNode* root , string& s){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        s += to_string(root->val) + "_";
        return;
    }
    inorder(root->left , s);
    inorder(root->right , s);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string S1 = "";
        string S2 = "";

        inorder(root1 , S1);
        inorder(root2 , S2);

        if(S1 == S2){
            return true;
        }else{
            return false;
        }
    }
};