// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         unordered_map<int,int>m;
//         m[0]=-1;
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//             m.insert({sum,i});
//             int rem = sum%k;
//             if(m.find(rem)!=m.end() && (i-m[rem])>1)
//                 return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(),rem,sum;
        unordered_map<int,int> mp;
        mp[0]=-1;
        sum=0;
        for(int i=0;i<n;i++)
        {sum+=nums[i];
            rem=sum%k;
    
            if(mp.find(rem)!=mp.end()&&(i-mp[rem])>=2)
                return true;
         else if(mp.find(rem)==mp.end())   
         mp[rem]=i;
        }
        return false;
    }
};