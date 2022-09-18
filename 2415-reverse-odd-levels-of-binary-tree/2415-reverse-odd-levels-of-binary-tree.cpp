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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        vector<vector<int>>v;
        while(!q.empty()){
            int h = q.size();
            vector<int>k;
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                k.push_back(temp->val);
            }
            v.push_back(k);
        }
        // q.clear();
        for(int i=0;i<v.size();i++){
            if(i%2!=0){
                reverse(v[i].begin(),v[i].end());
            }
        }
        int row = 0;
        q.push(root);
        while(!q.empty()){
            int h = q.size();
            vector<int>k;
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                temp->val = v[row][i];
            }
            row++;
        }
        return root;
    }
};