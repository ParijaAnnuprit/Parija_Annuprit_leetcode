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
    vector<vector<int>>v;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        helper(root,path,targetSum);
        return v;
    }
    void helper(TreeNode* root, vector<int>& path, int rem){
        if(root ==NULL) return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && rem == root->val){
            v.push_back(path);
        }
        helper(root->left, path, rem-root->val);
        helper(root->right, path, rem-root->val);
        path.pop_back();
    }
};