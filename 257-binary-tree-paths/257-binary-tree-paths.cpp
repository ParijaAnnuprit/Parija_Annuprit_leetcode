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
    vector<string>v;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root== NULL) return v;
        string s = to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            v.push_back(s);
            return v;
        }
        paths(root->left,s);
        paths(root->right,s);
        return v;
    }
    void paths(TreeNode* root, string s){
        if(root == NULL) return;
        s = s+ "->"+to_string(root->val);
        if(root->left == NULL && root->right == NULL) v.push_back(s);
        if(root->left) paths(root->left,s);
        // s = s+ "->"+to_string(root->val);
        if(root->right) paths(root->right,s);
    }
};