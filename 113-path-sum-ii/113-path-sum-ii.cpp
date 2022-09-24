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
        int sum =0;
        helper(root, path, sum, targetSum);
        return v;
        
    }
    void helper(TreeNode* root, vector<int>& path, int sum, int targetsum){
        if(root==NULL) return;
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right ==NULL && sum==targetsum){
            v.push_back(path);
        }
        if(root->left) helper(root->left, path, sum, targetsum);
        if(root->right) helper(root->right, path, sum, targetsum);
        path.pop_back();
        sum-=root->val;
    }
};