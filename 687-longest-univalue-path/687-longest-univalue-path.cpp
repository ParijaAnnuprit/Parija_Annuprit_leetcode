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
    int maxa = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        helper(root,INT_MIN);
        return maxa;
    }
    int helper(TreeNode* root, int parentvalue){
        if(root == nullptr) return 0;
        int leftcounter = helper(root->left,root->val);
        int rightcounter = helper(root->right,root->val);
        maxa = max(leftcounter+rightcounter, maxa);
        if(root->val == parentvalue) return max(leftcounter,rightcounter)+1;
        return 0;
    }
};


// class Solution {
// public:

// //initialize global counters with initial values of zeros
// int maxCounter=0;

// int helper(TreeNode *root, int parentValue){
    
//     //if there's no tree-> stop
//     if(!root)
//         return 0;
    
//     //recursively call the helper function with the left nodes
//     int leftCounter=helper(root->left, root->val);
//     //recursively call the helper function with the right nodes
//     int rightCounter=helper(root->right, root->val);
    
//     //save the maximum available counter 
//     maxCounter=max(leftCounter + rightCounter , maxCounter);
    
//     //check if the parent node value equals the current, left or right, node value-> add the largest value from the two counters by one
//     if(root->val==parentValue)
//         return max(leftCounter, rightCounter)+1;
        
//     return 0;
// }

// int longestUnivaluePath(TreeNode* root) {
    
//     //if there's no tree-> retrun 0
//     if(!root)
//         return 0;
    
//     //call the helper function with the main root node & a value without the range, as we started from -1000
//     helper(root, INT_MIN);

//     //return the maximum counter value
//     return maxCounter;
// }
// };