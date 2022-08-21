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
    int sum = 0;
    int findTilt(TreeNode* root) {
        if(root== NULL) return 0;
        sum+= abs(helper(root->left) - helper(root->right));
        if(root->left) findTilt(root->left);
        if(root->right) findTilt(root->right);
        return sum;
    }
    int helper(TreeNode* root){
        if(root== NULL) return 0;
        return (root->val + helper(root->left) + helper(root->right));
    }
};