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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        return binarytree(nums,0,nums.size()-1);
    }
    TreeNode* binarytree(vector<int>& nums, int b, int e){
        int val = INT_MIN;
        int ind;
        for(int i=b;i<=e;i++){
            val = max(val,nums[i]);
            ind = mpp[val];
        }
        TreeNode* temp = new TreeNode(val);
        if(b != ind) temp->left = binarytree(nums,b,ind-1);
        if(e != ind) temp->right = binarytree(nums, ind+1,e);
        return temp;
    }
};