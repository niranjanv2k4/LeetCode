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
    int sumRootToLeaf(TreeNode* root) { return recurse(root, 0); }

    int recurse(TreeNode* root, int num) {
        if (!root)
            return 0;

        num = (num << 1) + root->val;
        if (!root->left && !root->right)
            return num;

        int tot = 0;
        if (root->right)
            tot += recurse(root->right, num);

        if (root->left)
            tot += recurse(root->left, num);

        return tot;
    }
};