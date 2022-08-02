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

ListNode* merge(ListNode* l1, ListNode* l2){
    if(l1 == NULL)
        return l2;
     if(l2== NULL)
        return l1;
    if(l1->val <= l2->val){
        l1->next = merge(l1->next, l2);
        return l1;
    }
    if(l2->val <= l1->val){
        l2->next = merge(l2->next,l1);
        return l2;
    }
    return NULL;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
//         using recursion
//         we will be using merge sort here
//         first dividing the linked list
        if(head==NULL || head->next ==NULL)
            return head;
        ListNode temphead(-1,head);
        ListNode* dummy = &temphead;
        ListNode* temp = dummy;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            temp = temp->next;
        }
        temp->next = NULL;
        return merge(sortList(head),sortList(slow));
    }
};