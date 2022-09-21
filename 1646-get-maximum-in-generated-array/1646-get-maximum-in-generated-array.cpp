class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 || n==1) return n;
        vector<int>nums(n+2,0);
        nums[0] = 0;
        nums[1] = 1;
        int x = n/2;
        for(int i=1;i<=x;i++){
            nums[2*i] = nums[i];
            nums[2*i+1] = nums[i] + nums[i+1];
        }
        if(n%2==0){
            nums.pop_back();
            nums.pop_back();
        }
        if(n%2!=0) nums.pop_back();
        int maxa = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxa = max(maxa,nums[i]);
        }
        return maxa;
    }
};