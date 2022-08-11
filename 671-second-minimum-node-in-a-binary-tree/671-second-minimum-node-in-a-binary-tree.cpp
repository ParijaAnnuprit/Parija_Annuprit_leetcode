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
//     int min1 = INT_MAX;
//     int min2 = INT_MAX;
//     // vector<int>v;
//     int findSecondMinimumValue(TreeNode* root) {
//         inorder(root);
//         return min2<INT_MAX ? min2:-1;
//     }
//     void inorder(TreeNode* root){
//         if(root == NULL) return;
//         inorder(root->left);
//         if(min1<root->val){
//             min2 = min1;
//             min1 = root->val;
//         }
//         if(root->val < min2 && root->val > min1) min2 = root->val;
//         inorder(root->right);
//     }
// };

class Solution {
public:
    long long a = pow(2, 31), b = pow(2, 31);
    
    void findMin(TreeNode* root) {
	if(!root) return;
    findSecondMinimumValue(root->left);
    if (root->val < a) {
		b = a;
		a = root->val;
	}
    if (root->val < b && root->val > a) b = root->val;
    findSecondMinimumValue(root->right);
}
    
int findSecondMinimumValue(TreeNode* root) {
	findMin(root);
    return b == pow(2, 31) ? -1 : b;
        
    }
};