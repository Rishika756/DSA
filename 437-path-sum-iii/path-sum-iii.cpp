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
    int total = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0 ;

        findpathsum(root , targetSum , 0);
        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);

        return total;
    }

    void findpathsum(TreeNode* root , long long sum , long long  currentsum){
        if(root == NULL) return ;

        currentsum += root->val;
        if(sum == currentsum){
            total++;
        }
        
        findpathsum(root->left ,sum , currentsum);
        findpathsum(root->right ,sum , currentsum);
    }
};