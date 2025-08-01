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
 void collect(unordered_map<int, TreeNode*>& mp, TreeNode* node) {

        if(!node) return;
        mp[node->val] = node;
        collect(mp, node->left);
        collect(mp, node->right);
    }

    void maketree(unordered_map<int, TreeNode*>& mp, TreeNode*& node, int& cnt) {

        if(!node) return;
        if(!node->left && !node->right && mp[node->val]) {
            node = mp[node->val];
            mp[node->val] = NULL;
            cnt++;
        }
        maketree(mp, node->left, cnt);
        maketree(mp, node->right, cnt);
    }
bool validbst(TreeNode *root , TreeNode* low , TreeNode*high){
    if(!root) return true;
    if((low && root->val <= low->val) || (high && root->val >= high->val)) return false;

    return validbst(root->left , low , root) && validbst(root->right , root , high);
}
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if(trees.size() == 1){
            return validbst(trees[0] , NULL , NULL) ? trees[0] : NULL;
        }
        unordered_map<int , TreeNode*>mp;
        for(auto &node : trees){
            collect(mp , node->left);
            collect(mp , node->right);
        }
        TreeNode*root = NULL;
        for(auto &node : trees){
            if(mp.count(node->val)) mp[node->val] = node;
            else if(root) return NULL;
            else root = node;
        }
        if(!root) return NULL;
        int cnt = 0;
        maketree(mp , root , cnt);
        if(cnt != mp.size()) return NULL;

        return validbst(root , NULL , NULL) ? root : NULL;
    }
};