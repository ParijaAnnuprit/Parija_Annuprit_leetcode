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
//     ListNode* swapNodes(ListNode* head, int k) {
// //         using sliding window
//         if(head->next== NULL)
//             return head;
//         // ListNode* dummy = new ListNode(0);
//         // dummy->next = head;
//         ListNode*temp = head;
//         ListNode*temp2 = head;
//         ListNode*temp3 = head;
//         for(int i=0;i<k;i++){
//             temp = temp->next;
//             temp3 = temp3->next;
//         }
//         while(temp3->next != NULL){
//             temp2 = temp2->next;
//             temp3 = temp3->next;
//         }
//         swap(temp->val,temp2->val);
//         return head;
//     }
// };

class Solution {
public:

int getsize(ListNode* head){
    
    ListNode* temp = head;
    int ans = 0;
    
    while(temp != NULL){
        temp = temp->next;
        ans++;
    }
    return ans;
}

ListNode* swapNodes(ListNode* head, int k) {
    
    ListNode* temp1 = head;
    ListNode* temp2 = head;
    
    int i = 0;
    int n = getsize(head);
    
    while(temp1 != NULL && i < k-1){
        temp1 = temp1->next;
        i++;
    }
    
    i = 0;
    while(temp2 != NULL && i < n-k){
        temp2 = temp2->next;
        i++;
    }
    swap(temp1->val , temp2->val);
    return head;
}
};