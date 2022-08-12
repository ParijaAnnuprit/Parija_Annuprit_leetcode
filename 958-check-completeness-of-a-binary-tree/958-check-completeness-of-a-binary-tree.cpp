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
    bool isCompleteTree(TreeNode* root) {
        int x = height(root);
        int level = 0;
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            level++;
            int h = q.size();
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(level<x-1){
                    if(temp->left== NULL || temp->right == NULL) return false;
                }
                if(flag==0 && level==x-1){
                    if(temp->left == NULL && temp->right!=NULL) return false;
                    else if(temp->left==NULL || temp->right == NULL){
                        flag=1;
                        continue;
                    }
                 }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(level == x-1 && flag == 1){
                    if(temp->left!=NULL || temp->right!=NULL) return false;
                }
            }
            if(level==x-1)
                break;
        }
        return true;
    }
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return max(1+height(root->left),1+height(root->right));
    }
};