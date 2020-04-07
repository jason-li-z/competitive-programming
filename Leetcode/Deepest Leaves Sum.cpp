#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        // Can use a hashmap and map the depth of the leaf node, and add the max depths together
        unordered_map<TreeNode*, int> mp;
        int sum = 0;
        int max_depth = 0;
        helper(root, mp, 0, max_depth);
        for(const auto &a : mp) {
            if(a.second == max_depth) {
                sum += a.first->val;
            }
        }
        
        return sum;
    }
    
    void helper(TreeNode* root, unordered_map<TreeNode*, int> &mp, int depth, int &max_depth) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            mp[root] = depth;
        }
        max_depth = max(depth, max_depth);
        helper(root->left, mp, 1 + depth, max_depth);
        helper(root->right, mp, 1 + depth, max_depth);
    }
};