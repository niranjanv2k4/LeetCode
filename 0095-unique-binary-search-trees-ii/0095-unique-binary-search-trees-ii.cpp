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
    vector<TreeNode*> generateTrees(int n) { return createTrees(1, n); }

    vector<TreeNode*> createTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = createTrees(start, i - 1);
            vector<TreeNode*> right_trees = createTrees(i + 1, end);

            for (auto left : left_trees) {
                for (auto right : right_trees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};