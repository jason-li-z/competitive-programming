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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        int level = 0;
        dfs(root, level, result);
        reverse(result.begin(), result.end());
        return result;
    }
    
    void dfs(TreeNode* node, int lvl, vector<vector<int>> &result) {
        if(result.size() == lvl) {
            result.push_back(vector<int>());
        }
        
        result[lvl].push_back(node->val);
        if(node->left != nullptr) dfs(node->left, lvl + 1, result);
        if(node->right != nullptr) dfs(node->right, lvl + 1, result);
    }
};