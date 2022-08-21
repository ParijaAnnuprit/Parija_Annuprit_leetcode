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
// since require FIFO so queue
class CBTInserter {
public:
    queue<TreeNode*>incomplete;
    TreeNode* initial;
    CBTInserter(TreeNode* root) {
        initial = root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int h = q.size();
            for(int i=0;i<h;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(temp->left==NULL || temp->right== NULL) incomplete.push(temp);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* ret = incomplete.front();
        TreeNode* temp = new TreeNode(val);
        if(ret->left == NULL) ret->left = temp;
        else if(ret->right == NULL ){
            ret->right = temp;
            incomplete.pop();
        }
        incomplete.push(temp);
        return ret->val;
    }
    
    TreeNode* get_root() {
        return initial;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */