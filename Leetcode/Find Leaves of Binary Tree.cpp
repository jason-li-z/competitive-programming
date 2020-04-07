#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;  // Empty Case
        while (root != nullptr) {
            vector<int> leaves;
            root = removeLeaves(root, leaves);  // Keep pruning the same root,
                                                // simultaneously removing leaves until none left
            result.push_back(leaves);
        }
        return result;
    }

    TreeNode* removeLeaves(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(node->val);
            return nullptr;  // Return nullptr upwards so we can set the left/right as null
        }

        node->left = removeLeaves(node->left, result);    // Set the left as null if hit
        node->right = removeLeaves(node->right, result);  // Set right as nullptr if hit

        return node;
    }
};