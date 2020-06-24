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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> track;
        int max_val = INT_MIN;
        vector<int> result;
        
        if(root == nullptr) {
            return result;
        }
        
        dfs(root, track);
        
        for(const auto &a : track) {
            max_val = max(a.second, max_val);
        }
        
        for(const auto &a : track) {
            if(a.second == max_val) {
                result.push_back(a.first);
            }
        }
        
        return result;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int>&mp) {
        if(root == nullptr) {
            return;
        }
        mp[root->val]++;
        dfs(root->left, mp);
        dfs(root->right, mp);
    }
};