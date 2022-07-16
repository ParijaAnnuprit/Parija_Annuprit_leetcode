// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         unordered_map<int,int>mpp;
//         int sum=0;
//         int count=0;
//         mpp[0]=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//             mpp.insert({sum,i});
//             for(auto j=mpp.begin();j!=mpp.end();j++){
//                 if(sum-(j->first)%k==0)
//                     count++;
//             }
//             count--;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            int rem = (sum%k+k)%k; // (sum + k)%k
            if(rem==0)
                count++;
            if(mpp.find(rem)!=mpp.end())
                count+=mpp[rem];
            mpp[rem]++;
        }
        return count;
    }
};