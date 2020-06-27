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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_map<int, int> r1;
        bool ans = false;
        dfs(root1, r1);
        dfs2(root2,r1,target,ans);
        return ans;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int> &r1) {
        if(root==nullptr) return;
        r1[root->val]++;
        dfs(root->left, r1);
        dfs(root->right, r1);
    }
    
    void dfs2(TreeNode* root2, unordered_map<int, int> &r1, int target, bool& ans) {
        if(root2==nullptr) return;
        if(r1.find(target-root2->val) != r1.end()) {
            ans = true;
        }
        dfs2(root2->left, r1, target, ans);
        dfs2(root2->right, r1, target, ans);
    }
};