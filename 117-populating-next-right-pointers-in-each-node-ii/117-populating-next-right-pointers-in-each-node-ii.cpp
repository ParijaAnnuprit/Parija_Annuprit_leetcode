/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        vector<vector<Node*>>res;
        while(!q.empty()){
            int h = q.size();
            vector<Node*>v;
            for(int i=0;i<h;i++){
                Node* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp);
            }
            res.push_back(v);
        }
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size()-1;j++){
                res[i][j]->next = res[i][j+1];
            }
        }
        return root;
    }
};