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
//     TreeNode* bstToGst(TreeNode* root) {
//         inorder(root);
//         for(int i=0;i<v.size();i++){
//             int sum=0;
//             for(int j=i;j<v.size();j++){
//                 sum+=v[j];
//             }
//             v[i]=sum;
//         }
//         return construct(v,0,v.size()-1);
//     }
//     void inorder(TreeNode* root){
//         if(root==NULL) return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     TreeNode* construct(vector<int>& v, int b, int e){
//         int m = (b+e)/2;
//         TreeNode* temp = new TreeNode(v[m]);
//         if(b!=m) temp->left = construct(v,b,m-1);
//         if(e!=m) temp->right = construct(v,m+1,e);
//         return temp;
//     }
// };

class Solution {
public:
    int sumTree(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return root->val + sumTree(root->left)+sumTree(root->right);
        
    }
    int sum=INT_MIN;   //global

    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        if(sum<0)      //need to be calculated only once, not in every recursion
            sum=sumTree(root);
			
        bstToGst(root->left);
        
        int temp=root->val;
        root->val=sum;
        sum=sum-temp;
        
        bstToGst(root->right);
        return root;
    }
};