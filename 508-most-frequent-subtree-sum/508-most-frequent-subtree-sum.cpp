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
    int maxi = INT_MIN;
    int sum = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>v;
        fillmap(root);
        for(auto i:mpp){
            if(i.second==maxi)
                v.push_back(i.first);
        }
        return v;
    }
    void fillmap(TreeNode* root){
        sum = 0;
        inorder(root);
        mpp[sum]++;
        maxi = max(maxi,mpp[sum]);
        if(root->left) fillmap(root->left);
        if(root->right) fillmap(root->right);
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        sum+=root->val;
        inorder(root->right);
        return;
    }
};