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

struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp>q;
        int k = lists.size();
        for(int i=0;i<k;i++){
            if(lists[i] != NULL) q.push(lists[i]);
        }
        ListNode* head = new ListNode(-1);
        ListNode* dum = head;
        while(!q.empty()){
            ListNode* dummy = q.top();
            head->next = dummy;
            head = head->next;
            q.pop();
            if(dummy->next!=NULL) q.push(dummy->next);
        }
        return dum->next;
    }
};