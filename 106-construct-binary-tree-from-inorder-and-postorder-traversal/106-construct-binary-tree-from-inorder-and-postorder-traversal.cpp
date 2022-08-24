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
    unordered_map<int,int>mpp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       for(int i=0;i<inorder.size();i++){
           mpp[inorder[i]]=i;
       }
        return tree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* tree(vector<int>postorder,int postb,int poste, vector<int>& inorder, int inb,int ine){
        if(postb>poste || inb>ine) return NULL;
        TreeNode* temp = new TreeNode(postorder[poste]);
        int inroot = mpp[temp->val];
        int numl = inroot-inb;
        int numr = ine-inroot;
        temp->left = tree(postorder,postb,postb+numl-1,inorder,inb,inroot-1);
        temp->right = tree(postorder,postb+numl,poste-1,inorder,inroot+1,ine);
        return temp;
    }
};

// class Solution {
// public:
// TreeNode* construct(vector<int> &inorder,vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd,unordered_map<int,int> &mp)
// {
//    if(inStart>inEnd || postStart>postEnd)
//        return NULL;
//    TreeNode* root=new TreeNode(postorder[postEnd]);
//    int inRoot=mp[postorder[postEnd]];
//    int len=inRoot-inStart;
    
//    root->left=construct(inorder,postorder,inStart,inRoot-1,postStart,postStart+len-1,mp);
//    root->right=construct(inorder,postorder,inRoot+1,inEnd,postStart+len,postEnd-1,mp);
//         return root;
// }
// TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//     //code here
//     unordered_map<int,int> mp;
//     int n=inorder.size();
//     for(int i=0;i<n;i++)
//         mp[inorder[i]]=i;
//     return construct(inorder,postorder,0,n-1,0,n-1,mp);
// }
// };