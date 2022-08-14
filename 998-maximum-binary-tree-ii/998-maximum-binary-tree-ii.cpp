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
    unordered_map<int,int>mpp;
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inorder(root);
        v.push_back(val);
        for(int i=0;i<v.size();i++){
            mpp[v[i]]=i;
        }
        return construct(0,v.size()-1);
    }
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* construct(int b,int e){
        int a = INT_MIN;
        for(int i=b;i<=e;i++){
            a = max(a,v[i]);
        }
        int ind = mpp[a];
        TreeNode* temp = new TreeNode(a);
        if(ind != b) temp->left = construct(b,ind-1);
        if(ind != e) temp->right = construct(ind+1,e);
        return temp;
    }
};