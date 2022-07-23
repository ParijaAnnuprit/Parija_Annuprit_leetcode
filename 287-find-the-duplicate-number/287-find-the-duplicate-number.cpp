class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())
                return nums[i];
            s.insert({nums[i]});
        }
        return 0;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size()-1;
//         for(int i=1;i<n;i++){
//             for(int j=0;j<nums.size();j++){
//                 if(i==nums[j]){
//                     nums[j]= nums[j]^i;
//                     break;
//                 }
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=0)
//                 return nums[i];
//         }
//         return 0;
//     }
// };