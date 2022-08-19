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
//     tc = o(nh)
    vector<vector<int>>v;
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return helper(root,0);
    }
    int helper(TreeNode* root, int currsum){
        if(root == NULL) return 0;
        currsum = currsum*10 + root->val;
        if(root->left == NULL && root->right == NULL) return currsum;
        int left = helper(root->left,currsum);
        int right = helper(root->right,currsum);
        return left+right;
    }
};