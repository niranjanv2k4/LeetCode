class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = maxDepth(root);
        return dfs(root, depth, 1);
    }

    TreeNode* dfs(TreeNode* root, int depth, int lvl) {
        if (!root) return NULL;
        if (lvl == depth) return root;

        TreeNode* l = dfs(root->left, depth, lvl + 1);
        TreeNode* r = dfs(root->right, depth, lvl + 1);

        if (l && r) return root;
        return l ? l : r;
    }
};
