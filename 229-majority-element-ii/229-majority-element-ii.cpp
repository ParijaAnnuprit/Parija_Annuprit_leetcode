// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         vector<int>res;
//         int count = 1;
//         if(n==2 && nums[0]==nums[1]){
//             res.push_back(nums[0]);
//             return res;
//         }
//         else if(n==1 || n==2)
//             return nums;
//         for(int i=0;i<=n-1;i++){
//             if(nums[i]==nums[i+1])
//                 count++;
//             else{
//                 if(count>(n/3)){
//                     res.push_back(nums[i]);
//                     count=1;
//                 }
//                 else
//                     count=1;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            int times=0;
            if(find(ans.begin(), ans.end(), nums[i])==ans.end()){
            for(int j=0; j<n; j++){
                if(nums[j]==nums[i]){
                    times++;
                }
                if(times>(n/3)){
                    ans.push_back(nums[i]);
                    break;
                }
            }
            }
        }
        return ans;
    }
};