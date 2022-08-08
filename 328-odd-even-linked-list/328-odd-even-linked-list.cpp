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
    ListNode* oddEvenList(ListNode* head) {
        if(head ==NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* temp = head;
        int size = 0;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        ListNode* t3 = head->next;
        while(temp->next!=NULL){
            temp = temp->next;
            size++;
        }
        size++;
        if(size%2!=0){
            while( t1->next !=NULL && t2->next->next != NULL){
                t1->next = t1->next->next;
                t2->next = t2->next->next;
                t1= t1->next;
                t2 = t2->next;
            }
            t1->next = temp;
            t2->next =NULL;
            temp->next = t3;
        }
         if(size%2==0){
            while(t2->next !=NULL && t1->next->next != NULL){
                t1->next = t1->next->next;
                t2->next = t2->next->next;
                t1= t1->next;
                t2 = t2->next;
            }
            t2->next =NULL;
            t1->next = t3;
        }
        return head;
    }
};