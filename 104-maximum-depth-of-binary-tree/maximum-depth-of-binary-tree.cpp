class Solution {
public:
    int maxDepth(TreeNode* root) {
        return height(root);
    }

private:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return std::max(height(root->left), height(root->right)) + 1;
    }
};
