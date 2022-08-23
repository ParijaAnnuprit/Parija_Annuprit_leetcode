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
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return construct(v,0,v.size()-1);
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* construct(vector<int>& v, int b, int e){
        int m = (b+e)/2;
        TreeNode* temp = new TreeNode(v[m]);
        if(b!=m) temp->left = construct(v,b,m-1);
        if(b!=e) temp->right = construct(v,m+1,e);
        return temp;
    }
};