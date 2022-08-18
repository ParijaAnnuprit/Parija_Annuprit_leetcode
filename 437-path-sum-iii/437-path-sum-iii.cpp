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
    int x=0;
    int pathSum(TreeNode* root, int targetSum) {
        // vector<int>path;
        if(root == NULL ) return x;
        helper(root,targetSum);
        if(root->left) pathSum(root->left,targetSum);
        if(root->right) pathSum(root->right,targetSum);
        return x;
    }
    void helper(TreeNode* root, long long int rem){
        if(root == NULL) return;
        if(rem== root->val) x++;
        // path.push_back(root->val);
        helper(root->left,rem-root->val);
        helper(root->right,rem-root->val);
        // path.pop_back();
    }
};