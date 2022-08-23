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
        int level = 1 ;
        // int flag=0;
        q.push(root);
        while(!q.empty()){
            level++;
            int h = q.size();
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(level==depth){
                    // flag=1;
                    if(temp->left || !temp->left){
                        TreeNode* templ = temp->left;
                        TreeNode* n = new TreeNode(val);
                        temp->left = n;
                        n->left = templ; 
                    }
                    if(temp->right || !temp->right){
                        TreeNode* tempr = temp->right;
                        TreeNode* x = new TreeNode(val);
                        temp->right = x;
                        x->right = tempr;
                    }
                }
                else{
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            if(level==depth) break;
        }
        return root;
    }
};