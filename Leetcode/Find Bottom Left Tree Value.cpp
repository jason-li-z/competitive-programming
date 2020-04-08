#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
   public:
    int findBottomLeftValue(TreeNode *root) {
        // Idea is to go from right to left while updating root,
        // By the time we finish, root will be at the most left side, so we can return
        // The root's value
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            root = queue.front();
            queue.pop();
            if (root->right != nullptr) {
                queue.push(root->right);
            }
            if (root->left != nullptr) {
                queue.push(root->left);
            }
        }
        return root->val;
    }
};