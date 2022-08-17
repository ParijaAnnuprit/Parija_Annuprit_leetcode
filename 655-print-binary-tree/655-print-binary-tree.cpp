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
//     vector<vector<string>> printTree(TreeNode* root) {
//         int m = height(root);
//         int n = pow(2,m)-1;
//         vector<vector<string>> res(m, vector<string>(n,""));
//         res[0][(n-1)/2] = to_string(root->val);
//         return matrix(res,root,0,(n-1)/2,m-1);
//     }
//     int height(TreeNode* root){
//         if(root == NULL) return 0;
//         return max(1+ height(root->left), 1+ height(root->right));
//     }
//     vector<vector<string>> matrix(vector<vector<string>> &res ,TreeNode* root,int r,int c,int h){
//         if(root ==NULL) return res;
//         if(root->left) res[r+1][c-pow(2,h-r-1)] = to_string(root->left->val);
//         if(root->right) res[r+1][c+pow(2,h-r-1)] = to_string(root->right->val);
//         if(root->left) matrix(res,root->left, r+1,c-pow(2,h-r-1),h);
//         if(root->right) matrix(res,root->right,r,c+pow(2,h-r-1),h);
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = findheight(root, 0);
        int m = h+1, n = pow(2, h+1) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        inorder(root, 0, (n-1)/2, h, ans);
        return ans;
    }
    
    int findheight(TreeNode* root, int height){
        if(!root)return -1;
        int lh = findheight(root->left, height);
        int rh = findheight(root->right, height);
        
        return max(rh,lh) + 1;
    }
    
    void inorder(TreeNode* root, int row, int col ,int height, vector<vector<string>>&ans){
        if(!root)   return;
        int c = pow(2, height-row-1);
        if(root->left){
            inorder(root->left, row+1, col-c, height, ans);
        }
        ans[row][col] = to_string(root->val);
        if(root->right)
             inorder(root->right, row+1, col+c, height, ans);
    }
};