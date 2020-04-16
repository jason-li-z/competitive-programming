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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) {  // T can't be a subtree of S if s is null
            return false;
        } else if (isSameTree(s, t)) {  // Otherwise if they're the same tree we can return true
            return true;
        } else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);  // If return condition was not met,
                                                                     // recursive traverse the tree
        }
    }
    // Helper function to check if two nodes have same tree
    bool isSameTree(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) {  // Base case, if they're both null, they're equal
            return true;
        } else if (n1 != nullptr && n2 != nullptr && n1->val == n2->val) {              // Otherwise, if they both have same value
            return isSameTree(n1->left, n2->left) && isSameTree(n1->right, n2->right);  // Check the left subtree and right subtree are equal
        } else {
            return false;  // Otherwise return condition
        }
    }
};