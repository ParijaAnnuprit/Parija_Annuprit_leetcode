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
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
    TreeNode* helper(ListNode* head){
       if(head==NULL) return NULL;
        ListNode *dummy=NULL;
        ListNode* slow = head;
         
        ListNode* fast = head;
        // dummy->next = head;
        while(fast!=NULL && fast->next!=NULL){
            dummy=slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
         // if(head==slow) return nullptr;
    
        TreeNode* root = new TreeNode(slow->val);
        if(dummy){
            dummy->next=NULL;
            root->left = helper(head);
        }
        
      root->right = helper(slow->next);
        return root;
    }
};


// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int>v;
//         while(head != NULL){
//             v.push_back(head->val);
//             head= head->next;
//         }
//         return helper(v, 0, v.size()-1);    
//     }
//     TreeNode* helper(vector<int>v, int b, int e){
//         int mid = (b+e)/2;
//         TreeNode
//         if(b>e) return nullptr;
        
//     }
// };