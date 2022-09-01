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
    vector<string>v;
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        strings(root,s);
        int sum =0;
        for(int i=0;i<v.size();i++){
            sum+=stoi(v[i],nullptr,2);
        }
        return sum;
    }
    void strings(TreeNode* root, string  s){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->left == NULL && root->right== NULL) v.push_back(s);
        strings(root->left,s);
        strings(root->right,s);
    }
};