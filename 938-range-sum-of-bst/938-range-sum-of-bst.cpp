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
//     // vector<int>v;
//     int sum =0;
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         inorder(root,low,high);
//         return sum;
//     }
//     void inorder(TreeNode* root , int low , int high){
//         if(root == NULL) return;
//         inorder(root->left, low, high);
//         if(root->val>=low && root->val<=high) sum+= root->val;
//         inorder(root->right, low , high);
//     }
// };

class Solution {
public:
    // vector<int>v;
    int sum =0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        rangeSumBST(root->left, low,high);
        if(root->val >= low && root->val <= high) sum+=root->val;
        rangeSumBST(root->right,low,high);
        return sum;
    }
};