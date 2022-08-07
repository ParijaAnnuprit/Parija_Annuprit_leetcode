/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==NULL || head->next == NULL)
             return NULL;
        // ListNode temphead(-1,head);
        // ListNode* dummy = &temphead;
        ListNode* fast = head, *curr=head;
        ListNode* slow  = head;
        while(fast!=NULL and  fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                while(curr!=slow){
                    curr=curr->next;
                    slow=slow->next;
                }
                return slow;
            }
        } 
       return NULL;
    }
};

// ListNode *detectCycle(ListNode *head) {
//     ListNode* slow = head;
//     ListNode* fast = head;
    
//     // follow while loop untill slow and fast pointed toward same node
//     do{
//         if(fast == NULL || fast->next == NULL){
//             return NULL;
//         }
//         slow = slow->next;
//         fast = fast->next->next;
         
//     }while(fast!=slow);
    
//     // Now, update slow to head and move fast at a speed of 1 node
//     slow = head;
//     int cnt = 0;
//     while(slow!=fast){
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return slow;
// }
