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
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i]>v[0])
                return v[i];
        }
        return -1;
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};