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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return NULL;
        int rootval = postorder[idx--];
        TreeNode* root = new TreeNode(rootval);
        int index = -1;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == rootval) {
                index = i;
                break;
            }
        }
        root->right = solve(postorder, inorder, index + 1, end, idx);
        root->left = solve(postorder, inorder, start, index - 1, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return solve(postorder, inorder, 0, inorder.size() - 1, idx);
    }
};