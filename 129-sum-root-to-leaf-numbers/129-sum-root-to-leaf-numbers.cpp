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
// //     without backtracking
//     int sumNumbers(TreeNode* root) {
//         if(root==NULL) return 0;
//         return helper(root,0);
//     }
//     int helper(TreeNode* root, int currsum){
//         if(root == NULL) return 0;
//         currsum = currsum*10 + root->val;
//         if(root->left == NULL && root->right == NULL) return currsum;
//         int left = helper(root->left,currsum);
//         int right = helper(root->right,currsum);
//         return left+right;
//     }
// };

class Solution {
public:
//     with backtracking
    vector<int>v;
    int sumNumbers(TreeNode* root) {
        if(root== NULL) return  0;
        helper(root,0);
        int sum = 0;
        for(int i=0;i<v.size();i++){
            sum = sum+ v[i];
        }
        return sum;
    }
    void helper(TreeNode* root, int currsum){
        if(root== NULL) return;
        currsum = currsum*10 +root->val;
        if(root->left== NULL && root->right == NULL) v.push_back(currsum);
        helper(root->left,currsum);
        helper(root->right,currsum);
        // currsum = currsum-root->val;
        // currsum = currsum/10;
    }
};