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
//     int count =0;
//     int pseudoPalindromicPaths (TreeNode* root) {
//         unordered_map<int,int>mpp;
//         dfs(root, mpp);
//         return count;
//     }
//     void dfs(TreeNode* root, unordered_map<int,int>& mpp){
//         if(root->left ==NULL && root->right == NULL){
//             bool x = checkpath(mpp);
//             if(x) count++;
//             return;
//         }
//         mpp[root->val]++;
//         if(root->left) dfs(root->left, mpp);
//         if(root->right) dfs(root->right, mpp);
//         return;
//     }
//     bool checkpath(unordered_map<int,int>mpp){
//         int freq = 0;
//         for(auto i: mpp){
//             if(i.second%2 != 0) freq++;
//             if(freq>1) return false;
//         }
//         return true;
//     }
// };


class Solution {
public:
    int count =0;
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mpp;
        dfs(root, mpp);
        return count;
    }
    void dfs(TreeNode* root, unordered_map<int,int>& mpp){
        if(root->left ==NULL && root->right == NULL){
            mpp[root->val]++;   // increase it
            bool x = checkpath(mpp);
            if(x) count++;
            mpp[root->val]--;   // decrease it when backtracking
            return;
        }
        mpp[root->val]++;
        if(root->left) dfs(root->left, mpp);
        if(root->right) dfs(root->right, mpp);
        mpp[root->val]--; // decrease it when backtracking
    }
    bool checkpath(unordered_map<int,int>mpp){
        int freq = 0;
        for(auto i: mpp){
            if(i.second%2 != 0) freq++;
            if(freq>1) return false;
        }
        return true;
    }
};