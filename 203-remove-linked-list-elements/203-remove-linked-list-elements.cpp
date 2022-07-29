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
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode*temp1 = new ListNode(0);
//         temp1->next = temp1;;
//         ListNode* temp = head;
//         while(temp->next != NULL){
//             if(temp!= NULL && temp->val == val){
//                 temp1->next = temp->next;
//                 temp = temp->next;
//                 temp1 = temp1->next;
//             }
//             temp = temp->next;
//             temp1 = temp1->next;
//         }
//         return head;
//     }
// };

class Solution {
public:
ListNode* removeElements(ListNode* head, int val) {
ListNode * dummy =new ListNode(-1);
dummy->next=head;
ListNode * start=dummy;
while(start!=NULL && start->next !=NULL)
{
if(start->next->val==val)
{
ListNode *del=start->next;
start->next=del->next;
delete del;
}
else
{
start=start->next;
}
}
return dummy->next;
}
};