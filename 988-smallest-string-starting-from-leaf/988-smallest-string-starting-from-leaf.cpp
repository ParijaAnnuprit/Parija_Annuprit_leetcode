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
    string ans = "";
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        helper(root,s);
        return ans;
    }
    void helper(TreeNode* root,string s){
        if(root==NULL) return;
        s += root->val+'a';
        if(root->left== NULL && root->right== NULL){
            reverse(s.begin(),s.end());
            if(ans=="") ans = s;
            else if(s<ans) ans = s;
        }
        helper(root->left,s);
        helper(root->right,s);
    }
};


