/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
        path(root,p,v1);
        path(root,q,v2);
        for(int i=v1.size()-1;i>=0;i--){
            for(int j=0;j<v2.size();j++){
                if(v1[i]->val == v2[j]->val) return v1[i];
            }
        }
        return nullptr;
    }
    bool path(TreeNode* root, TreeNode* f, vector<TreeNode*> &v){
        if(root==NULL ) return false;
        v.push_back(root);
        if(root->val == f->val) return true;
        if(path(root->left,f,v) || path(root->right,f,v)) return true;
        v.pop_back();
        return false;
    }
};