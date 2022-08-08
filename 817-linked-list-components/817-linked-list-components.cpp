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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int p =0;
        while(head!=NULL){
            if(s.find(head->val)!=s.end()){
                while(s.find(head->val)!=s.end() && head->next!=NULL)
                    head = head->next;
                p++;
                 head = head->next;
            }
            else
                head= head->next;
        }
        return p;
    }
};