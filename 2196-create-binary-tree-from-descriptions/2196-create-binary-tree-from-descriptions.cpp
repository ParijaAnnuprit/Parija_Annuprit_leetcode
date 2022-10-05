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
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         TreeNode* dummy;
// //         parent,(child)
//         unordered_map<int ,TreeNode*>parent;
// //         child,(parent)
//         unordered_map<int,TreeNode*>child;
//          for(int i=0;i<descriptions.size();i++){
//              if(parent.find(descriptions[i][0])!=parent.end()){
//                  TreeNode* temp = parent[descriptions[i][0]];
//                  TreeNode* newnode = new TreeNode(descriptions[i][1]);
//                  if(descriptions[i][2]==1) temp->left = newnode;
//                  else temp->right = newnode;
//                  child[descriptions[i][1]] = newnode;
//              }
//              else if(child.find(descriptions[i][1])!=child.end()){
//                  TreeNode* temp = child[descriptions[i][1]];
//                  TreeNode* newnode = new TreeNode(descriptions[i][0]);
//                  if(descriptions[i][2]==1) newnode->left = temp;
//                  else newnode->right = temp;
//                  parent[descriptions[i][0]] = newnode;
//              }
//              else{
//                  TreeNode* newparent = new TreeNode(descriptions[i][0]);
//                  TreeNode* newchild = new TreeNode(descriptions[i][1]);
//                  if(descriptions[i][2]==1) newparent->left = newchild;
//                  else newparent->right = newchild;
//                  parent[descriptions[i][0]] = newparent;
//                  child[descriptions[i][1]] = newchild;
//              }
//              if(parent.find(descriptions[i][0])!=parent.end() && child.find(descriptions[i][0])==child.end()) dummy = parent[descriptions[i][0]];
//          }
//         return dummy;
//     }
// };



class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, std::pair<TreeNode *, TreeNode *>> treeDes;
		//Map stores <node value> = {self TreeNode *, parent TreeNode *}
        for (auto des : descriptions) {
            int parent = des[0], child = des[1], isleft = des[2]; 
            if (treeDes.find(parent) == treeDes.end()) {
                treeDes[parent] = {new TreeNode(parent), nullptr};
            } 
            if (treeDes.find(child) == treeDes.end()) {
                treeDes[child] = {new TreeNode(child), treeDes[parent].first};
            } else {
                treeDes[child].second = treeDes[parent].first;
            }
            if (isleft == 1) {
                treeDes[parent].first->left = treeDes[child].first;
            } else {
                treeDes[parent].first->right = treeDes[child].first;
            }
        }
        for (auto node : treeDes) {
            if (node.second.second == nullptr) {
                return node.second.first;
            }
        }
        return nullptr;
    }
};
