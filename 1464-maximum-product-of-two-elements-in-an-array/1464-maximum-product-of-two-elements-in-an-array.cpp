class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q;
        for(auto i:nums){
            q.push(i);
        }
        int x = q.top()-1;
        q.pop();
        return x*(q.top()-1);
    }
};