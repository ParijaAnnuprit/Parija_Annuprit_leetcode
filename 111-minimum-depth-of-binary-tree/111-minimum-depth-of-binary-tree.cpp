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
    int minDepth(TreeNode* root) {
      if(root==NULL)
          return 0;
       int x = 1+minDepth(root->left);
       int y = 1+minDepth(root->right);
        if(x==1)
            return y;
        else if(y==1)
            return x;
        return min(x,y);
    }
};
