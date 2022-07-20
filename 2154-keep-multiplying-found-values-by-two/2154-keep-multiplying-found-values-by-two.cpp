class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(q.front()<original)
                q.pop();
            else if(q.front()==original){
                original*=2;
                q.pop();
            }
        }
        return original;
    }
};