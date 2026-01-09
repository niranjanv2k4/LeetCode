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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = find_height(root);
        TreeNode* res = NULL;
        
        dfs(root, height - 1, res);

        return res?res:root;
    }

    int find_height(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(find_height(root->left), find_height(root->right));
    }

    void dfs(TreeNode* root, int height, TreeNode*& res) {
        if (!root)
            return;

        dfs(root->left, height - 1, res);
        dfs(root->right, height - 1, res);

        int left = find_height(root->left);
        int right = find_height(root->right);


        if (left == height && right == height) {
            res = root;
        } else if (left == height) {
            if (!res) {
                res = root->left;
            }
        } else if (right == height) {
            if (!res) {
                res = root->right;
            }
        }

        return;
    }
};