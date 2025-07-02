/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markparent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>&parent , TreeNode* target){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent;
        markparent(root , parent , target);
        unordered_map<TreeNode* , bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int distance = 0;
        while(!q.empty()){
            int size = q.size();
            if(distance++ == k){
                break;
            }
            for(int i = 0 ; i<size ; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && !visited[cur->left]){
                    q.push(cur->left);                      // down(left)
                    visited[cur->left] = true;
                }
                if(cur->right && !visited[cur->right]){
                    q.push(cur->right);                      // down(right)
                    visited[cur->right] = true;
                }
                if(parent[cur] && !visited[parent[cur]]){
                    q.push(parent[cur]);                     // up 
                    visited[parent[cur]] = true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }

};