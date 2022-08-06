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
    
    /*  instead of getting height of left and right subtree for each node
        we will modify our height function to return height if conditions are satisfied
        in the subtree and if the conditions are not satisfied, we will return a special value
        to represent the false.
        
        here since height cannot be -ve, we can use -1 as that special value
    */
    
    
    int evaluate(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        // Get the left height
        int lh = 0;
        if(root->left){
            lh = evaluate(root->left);
            if(lh == -1){               // if there is a voilation in left subtree
                return -1;              // return -1, no need to check further
            }
        }
        
        int rh = 0;
        if(root->right){
            rh = evaluate(root->right);
            if(rh == -1){
                return -1;
            }
        }
        
        // if we reached till now, it is clear that the subtrees have no voilation
        // So, we just need to check for the current node
        // if left and right heights have max diff of 1
        // we return the height of current tree
        // else -1 to represent voilation
        
        return (abs(lh - rh) <= 1)?(max(lh, rh)+1):(-1);
    }
    
    
    bool isBalanced(TreeNode* root) {
        if(evaluate(root) == -1){
            return false;
        }
        return true;
        
    }
};