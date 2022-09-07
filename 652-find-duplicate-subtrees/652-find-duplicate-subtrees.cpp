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
    unordered_map<string,pair<TreeNode*,int>>mpp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       vector<TreeNode*>v; 
        solve(root);
        for(auto i:mpp){
            if(i.second.second>1) v.push_back(i.second.first);
        }
        return v;
    }
    void solve(TreeNode* root){
        if(root==NULL) return;
        string s = "";
        inorder(root, s);
        if(mpp.find(s)!=mpp.end()){
            mpp[s].second++;
        }
        else if(mpp.find(s)==mpp.end()){
            mpp[s] = {root,1};
        }
        solve(root->left);
        solve(root->right);
    }
    void inorder(TreeNode* root, string& s){
        if(root==NULL){
            s+="#";
            return;
        }
        s+=to_string(root->val+ ',');
        inorder(root->left,s);
        inorder(root->right,s);
    }
};