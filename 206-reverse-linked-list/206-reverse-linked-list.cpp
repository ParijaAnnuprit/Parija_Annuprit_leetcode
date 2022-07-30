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


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
// // iterative using 3 pointer
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* newnode = NULL;
//         while(curr!=NULL){
//             newnode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = newnode;
            
//         }
//         return prev;
//     }
// };

class Solution {
public:
//     ListNode* reverseh(ListNode* head){
//         if(head->next== NULL) return head;
        
//         ListNode *temp=reverseh(head->next);
//         head->next->next=head;
//         head->next=NULL;
        
//         return temp;
//     }
    ListNode* reverseList(ListNode* head) {
// using recusion method
     //  ListNode* temp = head;
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
      return temp;
    }
};