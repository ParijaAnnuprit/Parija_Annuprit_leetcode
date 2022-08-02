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
    vector<int>v;
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>v;
        TreeNode* curr = root;
        if(curr==NULL)
            return v;
        v.push_back(curr->val);
        preorderTraversal(curr->left);
        preorderTraversal(curr->right);
        return v;
    }
};