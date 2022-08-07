/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         unordered_set<ListNode*>s;
        while(headB != NULL){
            s.insert(headB);
            headB = headB->next;
        }
        while(headA != NULL){
            if(s.find(headA)!= s.end())
                return headA;
            else
                headA = headA->next;
        }
        return NULL;
    }
};