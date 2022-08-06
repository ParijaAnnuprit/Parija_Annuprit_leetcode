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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;
        ListNode temphead(-1,head);
        unordered_set<int>s;
        ListNode *dummy = &temphead;
        ListNode* temp2 = dummy;
        ListNode* temp = head;
        while(temp!= NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                s.insert(temp->val);
                temp->next = temp->next->next;
                // temp = temp->next;
            }
            else
                temp = temp->next;
        }
        temp = dummy->next;
        while(temp!=NULL){
            if(s.find(temp->val)!=s.end()){
                temp2->next= temp->next;
                temp = temp2->next;
            }
            else{
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return dummy->next;
    }
};
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.