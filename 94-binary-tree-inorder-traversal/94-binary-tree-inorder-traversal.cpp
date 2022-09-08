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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>v;
        TreeNode* curr = root;
        while(true){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            else if(st.empty()) break;
            else{
                v.push_back(st.top()->val);
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return v;
    }
};