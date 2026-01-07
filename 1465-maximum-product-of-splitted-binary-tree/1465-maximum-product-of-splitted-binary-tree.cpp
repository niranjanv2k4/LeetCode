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
    int maxProduct(TreeNode* root) {
        long long res = 0;
        const int MOD = 1e9 + 7;
        dfs(root, res, recurse(root));
        return res % MOD;
    }

    int recurse(TreeNode* root){
        if(!root)
            return 0;
        return root->val + recurse(root->left) + recurse(root->right);
    }

    int dfs(TreeNode* root, long long& res, const long long tot){
        if(!root)
            return 0;
        
        int left = dfs(root->left, res, tot);
        int right = dfs(root->right, res, tot);

        res = max(res, 1LL*(tot - left)*left);
        res = max(res, 1LL*(tot - right)*right);

        return left + right + root->val;
    }
};