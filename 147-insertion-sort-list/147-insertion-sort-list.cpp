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
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode temphead(-1,head);
//         ListNode* dummy = &temphead;
//         ListNode* t = dummy;
//         ListNode* t2 = head;
//         head = head->next;
//         while(head){
//             while(t && t->next && t->next->val <head->val){
//                 t = t->next;
//             }
//             ListNode* nex = head->next;
//             t2->next = nex;
//             head->next = t->next;
//             t->next = head;
//             t2 = t2->next;
//             head = nex;
//             t = dummy;
//         }
//         return temphead.next;
//     }
// };

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		ListNode* t = dummy;
		while (head) {
			while (t && t->next && t->next->val < head->val) t = t->next;
			ListNode* nex = head->next;
			head->next = t->next;
			t->next = head;
			t = dummy;
            head= nex;
		}
		return dummy->next;
	}
};

// while (t && t->next && t->next->val < head->val) t = t->next;
// 			ListNode* nex = head->next;
// 			head->next = t->next;
// 			t->next = head;
// 			t = dummy;
//             head= nex;