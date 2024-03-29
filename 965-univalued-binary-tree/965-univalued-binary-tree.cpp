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
// class Solution {
// public:
//     int flag = 0;
//     bool isUnivalTree(TreeNode* root) {
//         // if(root== NULL ) return false;
//         helper(root, root->val);
//         if(flag == 1) return false;
//         return true;
//     }
//     void helper(TreeNode* root, int x){
//         if(root == NULL) return;
//         if(root->val != x) flag = 1;
//         helper(root->left,x);
//         helper(root->right,x);
//         // return true;
//     }
// };

class Solution {
public:
    int flag = 0;
    bool isUnivalTree(TreeNode* root) {
        return helper(root,root->val);
    }
    bool helper(TreeNode* root, int x){
        if(root == NULL) return true;
        if(root->val != x) return false;
        return helper(root->left ,x) && helper(root->right,x);
    }
};