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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = NULL;
        ListNode* temp2 = dummy;
        while(head!=NULL){
            if(head->val!=0){
                ListNode* temp = new ListNode(0);
                temp->next = NULL;
                while(head->val !=0){
                    temp->val =temp->val+ head->val;
                    head = head->next;
                }
                temp2->next = temp;
                temp2 = temp2->next;
            }
            else{
                head = head->next;
            }
        }
        return dummy->next;
    }
};