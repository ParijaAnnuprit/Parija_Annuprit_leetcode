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
//     unordered_map<TreeNode*,int>mpp;
//     int diameterOfBinaryTree(TreeNode* root) {
//         mpp[root] = 0;
//         int a = INT_MIN;
//         int b = INT_MAX;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int h = q.size();
//             for(int i=0;i<h;i++){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if(temp->left) {
//                     mpp[temp->left] = mpp[temp]-1;
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     mpp[temp->right]= mpp[temp]+1;
//                     q.push(temp->right);
//                 }
//                 a = max(a,mpp[temp]);
//                 b = min(b,mpp[temp]);
//             }
//         }
//         return a-b;
//     }
// };

class Solution {
public:
    int ans = 0;
    int longestPath(TreeNode *root){
        if(!root)
            return -1;
        int l = 1 + longestPath(root->left);
        int r = 1 + longestPath(root->right);
        ans = max(ans,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        longestPath(root);
        return ans;
    }
};