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
    // vector<TreeNode*>v;
    unordered_map<int,int>mpp;
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return tree(preorder,0, preorder.size()-1,inorder,0,inorder.size()-1);
    }
      TreeNode* tree(vector<int>& preorder, int pres, int pre, vector<int>& inorder, int ins, int ine){
        if(pres>pre || ins>ine) return NULL;
        TreeNode* root = new TreeNode(preorder[pres]);
        int inroot = mpp[root->val];
        int numsleft = inroot-ins;
        root->left = tree(preorder,pres+1,pres+numsleft,inorder,ins,inroot-1);
        root->right = tree(preorder,pres+numsleft+1,pre,inorder,inroot+1,ine);
        return root;
    }
};
