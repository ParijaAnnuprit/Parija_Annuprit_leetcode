// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int maxlen = 0;
//         int len=0;
//         if(nums.size()==1)
//             return 0;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]-nums[i-1]<=1){
//                 len++;
//                 maxlen = max(maxlen,len);
//             }
//             else if(nums[i]-nums[i-1]>1)
//                 len=0;
//         }
//         return maxlen;
//     }
// };

class Solution {
public:
    int findLHS(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mpp[nums[i]]++;
            }
            else if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=1;
            }
        }
        sort(nums.begin(),nums.end());
        int maxn=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1)
                maxn = max(maxn,mpp[nums[i]]+mpp[nums[i+1]]);
        }
        return maxn;
    }
};