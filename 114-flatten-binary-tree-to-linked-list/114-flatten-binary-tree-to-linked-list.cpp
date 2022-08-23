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
    void flatten(TreeNode* root) {
    if(root!=NULL ){
        preorder(root);
        root->left=NULL;
        root->right=NULL;
        TreeNode* temp = root;
        for(int i=1;i<v.size();i++){
            TreeNode* temp2 = new TreeNode(v[i]);
            temp->right = temp2;
            temp = temp->right;
        }
    }
    }
    void preorder(TreeNode* root){
        if(root==NULL) return;
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};