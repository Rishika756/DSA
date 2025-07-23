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
    TreeNode* findLastRight(TreeNode* node) {
        if (node->right == NULL) {
            return node;
        }
        return findLastRight(node->right);
    }

    TreeNode* helper(TreeNode* node) {
        if (node->left == NULL) {
            return node->right;
        }
        if (node->right == NULL) {
            return node->left;
        }

        TreeNode* rightSubtree = node->right;
        TreeNode* lastRight = findLastRight(node->left);
        lastRight->right = rightSubtree;
        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* curr = root;
        while (curr != NULL) {
            if (key < curr->val) {
                if (curr->left != NULL && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right != NULL && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }
};
