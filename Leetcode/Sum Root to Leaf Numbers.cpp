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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode* root, int curr_num) {
        if(root!=nullptr) {
            curr_num = curr_num * 10 + root->val;
            if(root->left == nullptr && root->right == nullptr) {
                ans += curr_num;
            }
            dfs(root->left, curr_num);
            dfs(root->right, curr_num);
        }     
        
    }
    
};