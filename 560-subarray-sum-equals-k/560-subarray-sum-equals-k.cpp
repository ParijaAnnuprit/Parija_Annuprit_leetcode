// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int,int>mpp;
//         int sum =0;
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//             if(sum==k)
//                 count++;
//             mpp[sum]=i;
//             for(auto i=mpp.begin();i!=mpp.end();i++){
//                 if((sum-(i->first))==k)
//                     count++;
//             }
//         }
//         if(k==0){
//             count= count-nums.size();
//         }
//         return count;
//     }
// };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};