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
// recusive
        if(list1==NULL)
            return list2;
        else if(list2 == NULL)
            return list1;
        else if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }    
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        return NULL;
    }
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
// // iterative two pointer
//         ListNode* dummy = new ListNode(0);
//         // ListNode* temp1 = list1;
//         // ListNode* temp2 = list2;
//         ListNode* tempf = dummy;
    
//         while(list1!=NULL && list2!= NULL){
//             if(list1->val<= list2->val){
//                 dummy->next = list1;
//                 dummy = dummy->next;
//                 list1= list1->next;
//             }
//             else if(list2->val< list1->val){
//                 dummy->next = list2;
//                 dummy = dummy->next;
//                 list2= list2->next;
//             }
            
//         }
//         if(list1== NULL){
//             dummy->next = list2;;
//         }
//         else if(list2== NULL){
//             dummy->next = list1;
//         }
//         return tempf->next;
//     }
// };