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

ListNode* reverse(ListNode* head){
    ListNode* newhead = NULL;
    if(head==NULL || head->next == NULL){
        return head;
    }
    else{
        newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
    }
    return newhead;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
//         here i did reverse the second half using recursion
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* revhead = NULL;
        if(head->next == NULL)
            return true;
        else if(head->next->next == NULL){
            if(head->val == head->next->val)
                return true;
            else
                return false;
        }
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
//           odd case (odd always above even since if only three nodes then problem)
            if(fast->next == NULL){
                revhead = reverse(slow->next->next);
                break;
            }
//             even case
            else if(fast->next->next == NULL){
                slow = slow->next;
                revhead = reverse(slow->next);
                break;
            }
            slow = slow->next;
        }
        while(revhead!=NULL){
            if(revhead->val != head->val)
                return false;
            revhead = revhead->next;
            head = head->next;
        }
        return true;
    }
};

// ListNode* getsize(ListNode* head){
//     while(head!=NULL){
//         head = head->next;
//         size++;
//     }
// }

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
// //      total recursion
//         ListNode* dummy = NULL;
//         dummy->next = head;
//        int size = getsize(dummy); 
//     }
// };