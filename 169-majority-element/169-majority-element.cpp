// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int count = 1;
//         if(n==1 || n==2)
//             return nums[0];
//         for(int i=0;i<n;i++){
//             if(nums[i] == nums[i+1])
//                 count++;
//             else if(nums[i]!= nums[i+1]){
//                 if(count>(n/2))
//                     return nums[i];
//                 else{
//                     count=1;
//                 }
                    
//             }
//         }
//         return -1;
//         // return count;
//     }
// };




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mpp[nums[i]]++;
                if(mpp[nums[i]]>(nums.size()/2))
                    return nums[i];
            }
            else{
                mpp[nums[i]]=1;
            }
        }
        return 1;
    }
};