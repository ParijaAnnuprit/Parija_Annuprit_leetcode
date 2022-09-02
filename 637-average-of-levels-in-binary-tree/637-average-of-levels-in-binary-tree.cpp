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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>res;
        while(!q.empty()){
            int h = q.size();
            vector<int>v;
            int count = 0;
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
                count++;
            }
            double sum = 0;
            for(int j =0;j<v.size();j++){
                sum+=v[j];
            }
            double x = sum/count;
            res.push_back(x);
        }
        return res;
    }
};