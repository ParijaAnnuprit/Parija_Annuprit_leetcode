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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>level;
        while(!q.empty()){
            int x = q.size();
            level.clear();
            for(int i=0;i<x;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                level.push_back(temp->val);
            }
        }
        int sum = 0;
        for(int i=0;i<level.size();i++){
            sum += level[i];
        }
        return sum;
    }
};