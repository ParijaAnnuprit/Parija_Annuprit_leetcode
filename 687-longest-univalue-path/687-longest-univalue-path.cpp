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
    int maxa =0;
    int longestUnivaluePath(TreeNode* root) {
        maxpath(root);
        return maxa;
    }
    int maxpath(TreeNode* root){
        if(root==nullptr) return 0;
        int left = maxpath(root->left);
        int right = maxpath(root->right);
        bool flagl = false;
        bool flagr = false;
        if(root->left && root->val == root->left->val){
            left = left+1;
            flagl= true;
        }
        if(root->right && root->val == root->right->val){
            right = right+1;
            flagr = true;
        }
        if(flagl && flagr){
            maxa = max(maxa,left+right);
            return max(left,right);
        }
        else if(flagl){
            maxa = max(maxa,left);
            return left;
        }
        else if(flagr){
            maxa = max(maxa,right);
            return right;
        }
        return 0;
    }
};