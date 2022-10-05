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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int h = q.size();
            level++;
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(level==depth){
                    if(temp->left || !temp->left){
                        TreeNode* node = temp->left;
                        TreeNode* newnode = new TreeNode(val);
                        temp->left = newnode;
                        newnode->left = node;
                    }
                    if(temp->right || !temp->right){
                        TreeNode* node = temp->right;
                        TreeNode* newnode = new TreeNode(val);
                        temp->right = newnode;
                        newnode->right = node;
                    }
                }
                else{
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            if(level == depth) break;
        }
        return root;
    }
};