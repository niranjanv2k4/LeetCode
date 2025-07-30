/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int& max_val) {
        if (!root)
            return 0;

        int left = helper(root->left, max_val);
        int right = helper(root->right, max_val);

        max_val = max(left + right, max_val);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_val = 0;
        helper(root, max_val);
        return max_val;
    }
};