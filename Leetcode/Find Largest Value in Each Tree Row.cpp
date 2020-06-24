#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            // Keep track of size so we can process nodes that belong that level
            int curr_max = INT_MIN;
            int n = queue.size();
            // Process nodes belonging in same level
            for (int i = 0; i < n; i++) {
                TreeNode* curr = queue.front(); queue.pop();
                // Check for max in this level
                curr_max = max(curr_max, curr->val);
                // Add this node's children to the queue to process after
                if(curr->left != nullptr) {
                    queue.push(curr->left);
                }
                if(curr->right != nullptr) {
                    queue.push(curr->right);
                }
            }
            // Add the max of that level to result
            result.push_back(curr_max);
        }
        return result;
    }
};