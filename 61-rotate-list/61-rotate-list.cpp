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
//     ListNode* rotateRight(ListNode* head, int k) {
//         int size = 0;
//         ListNode* tail = head;
//         while(tail->next!=NULL){
//             size++;
//             tail = tail->next;
//         }
//         size++;
//         ListNode* temp = head;
//         k%=size;
//         int x = size-k-1;
//         while(x>0){
//             temp = temp->next;
//             x--;
//         }
//         tail->next = head;
//         ListNode *t=temp->next;
//         temp->next = NULL;
//         return t;
//     }
// };



int len(ListNode* head){
    int cnt = 0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
}
class Solution{
public:
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL){
        return head;
    }
    
    // find the length 
    int l = len(head);
    // if k == n then lo traverse required because all node again comes at same poistion 
    // if k is greater than length then k again traverse in loop and  hence we take k = k%l to reduce cycles
    k = k%l;
    if(k==0){
        return head;
    }
    
    // to store new head
    ListNode* dummy = new ListNode(0);
    
    // to traverse old head
    ListNode* temp = head;
    
    // to travese from new head
    ListNode* temp1;
    
    // find last node and store node next as new head and update it as null
    int x = l - k - 1;
    while(x--){
        temp = temp->next;
    }
    
    dummy->next = temp->next;
    temp1 = temp->next;
    
    temp->next = NULL;
    
    // last node next update to given head
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = head;
    return dummy->next;
    
}
};