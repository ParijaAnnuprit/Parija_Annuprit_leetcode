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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         iterative- using new linked list
        // ListNode temphead(-1,head);
        ListNode* dummy = new ListNode(-1);
        ListNode* dupdum = dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                ListNode* temp = new ListNode(list1->val);
                dupdum->next = temp;
                dupdum = dupdum->next;
                list1 = list1->next;
            }
            else if(list2->val <= list1->val){
                ListNode* temp = new ListNode(list2->val);
                dupdum->next = temp;
                dupdum = dupdum->next;
                list2 = list2->next;
            }
        }
        if(list1!=NULL)
            dupdum->next  = list1;
        if(list2!=NULL)  dupdum->next = list2;
        return dummy->next;
    }
};