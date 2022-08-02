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
//     vector<int> preorderTraversal(TreeNode* root) {
//         // vector<int>v;
//         TreeNode* curr = root;
//         if(curr==NULL)
//             return v;
//         v.push_back(curr->val);
//         preorderTraversal(curr->left);
//         preorderTraversal(curr->right);
//         return v;
//     }
// };

class Solution {
public:
    // vector<int>v;
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(true){
            if(curr !=NULL){
                v.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()) break;
                else {
                    curr = st.top();
                    curr = curr->right;
                    st.pop();
                }
            }
        }
        return v;
    }
};