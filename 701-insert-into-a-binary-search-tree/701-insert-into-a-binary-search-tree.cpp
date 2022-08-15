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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        inorder(root);
        int i=0;
        if(val>v[v.size()-1]) v.push_back(val);
        else{
            while(val>v[i] && i<v.size()) i++;
            v.push_back(INT_MIN);
            for(int j=v.size()-2;j>=i;j--) v[j+1]=v[j];
            v[i]=val;
        }
        return construct(0,v.size()-1);
    }
    void inorder(TreeNode* root){
        if(root == NULL ) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* construct(int b,int e){
        int mid = (b+e)/2;
        TreeNode* temp = new TreeNode(v[mid]);
        if(b!= mid) temp->left = construct(b,mid-1);
        if(e!= mid) temp->right = construct(mid+1,e);
        return temp;
    }
};