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
    // int maxa = INT_MIN;
    int count = 0;
    int goodNodes(TreeNode* root) {
        search(root, root->val);
        return count;
    }
    void search(TreeNode* root , int currmax){
        if(root ==NULL) return;
        if(root->val >= currmax){
            count++;
            currmax = root->val;
        }
        search(root->left,currmax);
        search(root->right,currmax);
    }
};


// class Solution {
// public:
//     int count = 0;
//     void dfs(TreeNode* node,int curMax){
//         if (!node) return;
        
//         if (node->val >= curMax){
//             count++;
//             curMax = node->val;
//         }
//         dfs(node->left, curMax);
//         dfs(node->right, curMax);
//     }
//     int goodNodes(TreeNode* root) {
//         dfs(root, root->val);
//         return count;
//     }
// };