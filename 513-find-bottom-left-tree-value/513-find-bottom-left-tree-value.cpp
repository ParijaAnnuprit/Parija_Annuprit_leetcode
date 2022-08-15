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
    int findBottomLeftValue(TreeNode* root) {
        int k = height(root);
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int h = q.size();
            level++;
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(level == k)
                    return temp->val;
            }
        }
        return 0;
    }
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return max(1+height(root->left),1+height(root->right));
    }
};