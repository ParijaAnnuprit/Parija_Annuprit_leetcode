class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<1)
                continue;
            else{
                if(nums[i]==ans)
                    ans++;
                else if(nums[i]>ans)
                    return ans;
            }
        }
        return ans;
    }
};