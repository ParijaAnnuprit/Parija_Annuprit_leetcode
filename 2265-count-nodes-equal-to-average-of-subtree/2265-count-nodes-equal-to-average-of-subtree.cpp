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
// class Solution {
// public:
//     vector<int>v;
//     int n =0;
//     int averageOfSubtree(TreeNode* root) {
//         inorder(root);
//         int sum =0;
//         int avg=0;
//         if(v.size()==0)
//             avg=0;
//         else{
//             for(int i=0;i<v.size();i++){
//                 sum+=v[i];
//             }
//             avg = sum/v.size();
//             if(root->val==avg)
//                 n++;
//             }
//         v.clear();
//         if(root->left) averageOfSubtree(root->left);
//         if(root->right) averageOfSubtree(root->right);
//         return n;
//     }
//     void inorder(TreeNode* root){
//         if(root== NULL) return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
// };

class Solution {
public:
    int cnt=0;
    unordered_map<TreeNode*,pair<int,int>>mp;
    void solve(TreeNode* root)
    {
       if(!root)return;
       if(!root->left && !root->right)
       {
            cnt++;
            mp[root].first=root->val;
            mp[root].second=1;
           return;
       }
      solve(root->left);
      solve(root->right); 
      int x=(mp[root->left].first+mp[root->right].first+root->val)/(mp[root->left].second+mp[root->right].second+1);
        if(x==root->val)cnt++;
        mp[root].first=(mp[root->left].first+mp[root->right].first+root->val);
        mp[root].second=mp[root->left].second+mp[root->right].second+1;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        solve(root);
        return cnt;
    }
};