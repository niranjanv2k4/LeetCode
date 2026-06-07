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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;
        for (auto description : descriptions) {
            st.insert(description[1]);
            mp[description[1]] = new TreeNode(description[1]);
        }

        TreeNode* root = nullptr;
        for (auto description : descriptions) {
            if (st.find(description[0]) == st.end()) {
                root = new TreeNode(description[0]);
                break;
            }
        }

        mp[root->val] = root;

        for (auto description : descriptions) {
            int parent = description[0], child = description[1],
                isLeft = description[2];
            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];
        }

        return root;
    }
};