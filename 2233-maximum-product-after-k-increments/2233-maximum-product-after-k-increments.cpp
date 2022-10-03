class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        long long mod = pow(10,9)+7;
        long long y = 1;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        while(k>0){
            int x = q.top();
            q.pop();
            x+=1;
            q.push(x);
            k--;
        }
        while(!q.empty()){
            int z = q.top();
            q.pop();
            y = (y*z)%mod;
        }
        return y;
    }
};