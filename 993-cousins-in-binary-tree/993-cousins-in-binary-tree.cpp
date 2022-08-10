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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>level;
        int flag = 0;
        while(!q.empty()){
            int n = q.size();
            // vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && temp->right &&(temp->left->val == x && temp->right->val== y) ) return false;
                if(temp->left && temp->right && temp->left->val== y && temp-> right->val== x) return false;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right !=NULL) q.push(temp->right);
                level.push_back(temp->val);
            }
            for(int j=0;j<level.size();j++){
                if(level[j]==x || level[j]==y)
                    flag++;
            }
            if(flag==2)
                return true;
            flag =0;
            level.clear();
        }
        return false;
    }
};

// class Solution {
// public:
//     Solution(){
//         ios::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//     }
//     void dfs(TreeNode* root,int x,int y,pair<int,int>&X,pair<int,int>&Y,int depth,int parent){
        
//         if(root==NULL) return;
//         if(root->val==x) {
//             X.first=parent;
//             X.second=depth;
//             return;
//         }
//         if(root->val==y){
//             Y.first=parent;
//             Y.second=depth;
//             return;
//         }
//         dfs(root->left,x,y,X,Y,depth+1,root->val);
//         dfs(root->right,x,y,X,Y,depth+1,root->val);
        
//     }
    
//     bool isCousins(TreeNode* root, int x, int y) {
       
        
//         pair<int,int> X={-1,-1};
//         pair<int,int> Y={-1,-1};
        
//         dfs(root,x,y,X,Y,0,-1);
//         //cout<<X.first<<" "<<Y.first<<" "<<X.second<<" "<<Y.second;
        
//         return X.first!=Y.first and X.second==Y.second;
        
        
//     }
// };