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
    TreeNode* pruneTree(TreeNode* root) {
        return searchone(root) ? root:NULL;
        
    }
    bool searchone(TreeNode* root){
        if(root==NULL) return false;
        bool left = searchone(root->left);
        bool right = searchone(root->right);
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        return(root->val == 1|| left|| right);
    }
};