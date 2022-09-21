class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
             if(nums[i]%2==0) sum+=nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int x= nums[queries[i][1]]+queries[i][0];
            if(x%2==0 && nums[queries[i][1]]%2==0){
                sum-=nums[queries[i][1]];
                sum+=x;
                nums[queries[i][1]] = x;
                v.push_back(sum);
            }
            else if(x%2==0 && nums[queries[i][1]]%2!=0){
                sum+=x;
                nums[queries[i][1]]=x;
                v.push_back(sum);
            }
            else if(x%2!=0 && nums[queries[i][1]]%2==0){
                sum-=nums[queries[i][1]];
                nums[queries[i][1]] = x;
                v.push_back(sum);
            }
            else if(x%2!=0 && nums[queries[i][1]]%2!=0){
                nums[queries[i][1]]=x;
                v.push_back(sum);
            }
        }
        return v;
    }
};