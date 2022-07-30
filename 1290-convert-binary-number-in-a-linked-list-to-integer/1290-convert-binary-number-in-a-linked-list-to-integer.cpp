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

int getsize(ListNode* h){
    int size = 0;
    while(h !=NULL){
        h = h->next;
        size++;
    }
    return size;
}

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode*temp = head;
        int x = getsize(temp);
        int y = x-1;
        int sum = 0;
        while(temp!=NULL){
            if(temp->val ==1){
                sum = sum+ pow(2,y);
                y--;
                temp= temp->next;
            }
            else{
                y--;
                temp = temp->next;
            }
        }
        return sum;
    }
};