class Solution {
    public int maxDepth(TreeNode root) {
        return height(root);
    }
    int height(TreeNode root) {
        if(root == null)return 0;
        return Math.max(height(root.left), height(root.right)) + 1;
    }
}