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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = head;
        dummy->next = head;
        int size = 0;
        while(dummy->next!= NULL){
            dummy = dummy->next;
            size++;
        }
        // if(size==1 && n==1)
        //     return NULL;
        ListNode* dummy2 = new ListNode(-1);
        dummy2->next = head;
        int x= size-n;
        if(x==0)
            return head->next;
        while(x>0){
            dummy2 = dummy2->next;
            temp = temp->next;
            x--;
        } 
        dummy2->next = temp->next;
        //delete(temp);
        return head;
    }
};