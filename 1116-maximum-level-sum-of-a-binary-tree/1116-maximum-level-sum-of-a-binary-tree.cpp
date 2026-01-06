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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_val = root->val, level = 1, res = 1;

        while(!q.empty()){
            int size = q.size();
            int temp = 0;
            while(size--){
                TreeNode* curr_node = q.front();
                q.pop();
                temp += curr_node->val;
                
                if(curr_node->left){
                    q.push(curr_node->left);
                }
                if(curr_node->right){
                    q.push(curr_node->right);
                }
            }
            if(temp > max_val){
                max_val = temp;
                res = level;
            }
            level++;
        }

        return res;
    }
};