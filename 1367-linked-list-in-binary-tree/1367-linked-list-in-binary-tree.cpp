/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* temp = NULL;
    bool isSubPath(ListNode* head, TreeNode* root) {
        temp = head;
        return test(head,root);
    }
    bool test(ListNode* head,TreeNode* root){
        if(root==NULL) return false;
        bool x = subpath(head,root);
        if(x) return true;
        return test(head,root->left)||test(head,root->right);
        
    }
    bool subpath(ListNode* head, TreeNode* root){
        if(head==NULL) return true;
        if(root==NULL) return false;
        if(root->val != head->val){
            if(root->val==temp->val) return subpath(temp,root);
            else return (subpath(temp,root->left) || subpath(temp,root->right));
        }
        return (subpath(head->next, root->left) || subpath(head->next, root->right));
    }
};

