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
    unordered_set<int>s;
    int flag = 0;
    bool findTarget(TreeNode* root, int k) {
        helper(root,k);
        if(flag == 1)
            return true;
        return false;
    }
    void helper(TreeNode* root, int k){
        if(root == NULL) return;
        helper(root->left,k);
        if(s.find(k-root->val)!=s.end()){
            flag = 1;
            return;
        }
        else{
            s.insert(root->val);
        }
        helper(root->right,k);
    }
};