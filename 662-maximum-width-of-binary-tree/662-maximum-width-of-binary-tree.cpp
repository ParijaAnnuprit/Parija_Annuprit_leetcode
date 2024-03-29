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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, unsigned int> m;
        m[root] = 1;
        q.push(root);
        unsigned int ans = 1;
        while(!q.empty()){
            int size = q.size(), start, end;
            for(int i=1;i<=size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i == 1)
                    start = m[curr];
                if(i == size)
                    end = m[curr];
                if(curr->left){
                    q.push(curr->left);
                    m[curr->left] = 2*m[curr];
                }
                if(curr->right){
                    q.push(curr->right);
                    m[curr->right] = 2*m[curr]+1;
                }
            }
            ans = max(ans, (unsigned int)end-start+1);
        }
        return ans;
    }
};