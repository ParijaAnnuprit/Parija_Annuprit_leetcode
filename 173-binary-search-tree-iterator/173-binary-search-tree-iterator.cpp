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
// class BSTIterator {
// public:
//     stack<TreeNode*>st;
//     BSTIterator(TreeNode* root) {
//         TreeNode* temp = root;
//         while(temp!=NULL){
//             st.push(temp);
//             temp = temp->left;
//         }
//     }
    
//     int next() {
//         TreeNode* temp2 = st.top();
//         st.pop();
//         if(temp2->right) BSTIterator(temp2->right);
//         return temp2->val;
//     }
    
//     bool hasNext() {
//         if(!st.empty()) return true;
//         return false;
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


class BSTIterator {
public:
    vector<int>v;
    int i=0;
    void inorder(TreeNode* root){
        if(root== NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        if(i>v.size()-1) return false;
        return true;
    }
};