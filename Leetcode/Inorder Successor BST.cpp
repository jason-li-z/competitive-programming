/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        TreeNode* curr = root;
        while(curr != nullptr) {
            if(curr->val <= p->val) {
                curr = curr->right;
            } else {
                ans = curr;
                curr = curr->left;
            }
        }
        return ans;
    }

};