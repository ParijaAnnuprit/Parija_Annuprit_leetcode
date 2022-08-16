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
    TreeNode* invertTree(TreeNode* root) {
        if(root ==NULL) return nullptr;
        TreeNode* temp = root->left;
        TreeNode* temp2 = root->right;
        root->left = temp2;
        root->right = temp;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
        return root;
    }
};