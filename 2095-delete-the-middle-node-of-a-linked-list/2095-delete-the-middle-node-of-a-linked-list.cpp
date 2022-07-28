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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode temphead(-1,head);
        ListNode *slow=&temphead;
        ListNode* fast = head;
       // ListNode* temp = NULL;
       
            while(fast !=NULL && fast->next != NULL){
              
                slow = slow->next;
                fast = fast->next->next;
            }
            slow->next = slow->next->next;
           // delete(slow);
        
        return temphead.next;
    }
};