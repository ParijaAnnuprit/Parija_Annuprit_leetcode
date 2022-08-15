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
    int maxi = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi,lh+rh);
        if(root->left) diameterOfBinaryTree(root->left);
        if(root->right) diameterOfBinaryTree(root->right);
        return maxi;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return max(1+height(root->left),1+height(root->right));
    }
};