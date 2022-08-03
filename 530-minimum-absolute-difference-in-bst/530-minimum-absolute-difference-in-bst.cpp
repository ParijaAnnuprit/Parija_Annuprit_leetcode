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
//     vector<int>v;
//     void inorder(TreeNode* root){
//         if(root==NULL)
//             return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     int getMinimumDifference(TreeNode* root) {
//         TreeNode* curr = root;
//         // vector<int>res;
//         inorder(curr);
//         int diff = INT_MAX;
//         sort(v.begin(),v.end());
//         for(int i=1;i<v.size();i++)
//             diff = min(diff, v[i]-v[i-1]);
//         // sort(res.begin(),res.end());
//         return diff;
//     }
// };

class Solution {
    TreeNode* pre = nullptr;
    int minimum = std::numeric_limits<int>:: max();
public:
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if(pre) {
            minimum = min(node->val - pre->val, minimum);
        }
        pre = node;
        inorder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minimum;
    }

};