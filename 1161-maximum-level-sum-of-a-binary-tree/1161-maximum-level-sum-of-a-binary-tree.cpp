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
  
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0, j=0;
        int maxsum = INT_MIN;
        while(!q.empty()){
            int h = q.size();
            int sum = 0;
            level++;
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sum+=temp->val;
            }
            
            if(maxsum < sum){
                maxsum=sum;
                j=level;
            }
        
        }
    
        return j;
    }
};