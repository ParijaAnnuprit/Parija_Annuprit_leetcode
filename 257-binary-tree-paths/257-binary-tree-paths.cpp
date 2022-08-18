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
//  */
// class Solution {
// public:
//     vector<string>v;
//     vector<string> binaryTreePaths(TreeNode* root) {
//         if(root== NULL) return v;
//         string s = to_string(root->val);
//         if(root->left== NULL && root->right == NULL){
//             v.push_back(s);
//             return v;
//         }
//         paths(root->left,s);
//         paths(root->right,s);
//         return v;
//     }
//     void paths(TreeNode* root, string s){
//         if(root == NULL) return; 
//         s = s+ "->"+to_string(root->val);
//         if(root->left == NULL && root->right == NULL) v.push_back(s);
//         if(root->left) paths(root->left,s);
//         if(root->right) paths(root->right,s);
//     }
// };

 // */
class Solution {
public:
    void path(TreeNode* root , vector<string> &ans, string output ){
		// base case
		if( root == NULL ){
			return;
		}
    
    // if  root is not null push the data into string
    output += to_string( root->val);
    
    // if any left or right node of root exist push ->
    if( root->left || root->right ){
        output += "->";
    }
    
    if( !root->left && !root->right ){
        ans.push_back( output); // store ans;
    }
    
    
    //leftside
    if(root->left)
        path(root->left , ans, output);
    
    //rightside
    if(root->right)
        path(root->right , ans, output);
    
    // output.pop_back();  // backtrack
    
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;  // to store all paths to leaf
    
    string output = "";  // to store individual path in a recursive call
    
    path( root , ans, output );
    
    return ans;
}
};