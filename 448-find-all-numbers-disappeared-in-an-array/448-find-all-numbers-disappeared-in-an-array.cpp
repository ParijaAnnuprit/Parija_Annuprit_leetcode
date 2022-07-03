// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         int c=1;
//         vector<int>res;
//         if(nums[0]!=1)
//             res.push_back(1);
//         for(int i=1;i<n;i++){
//             if(nums[i]!=c){
//                 res.push_back(c);
//                 c++;
//             }
//             else if(nums[i]==nums[i-1])
//                 continue;
//             else if(nums[i]==c){
//                 c++;
//                 continue;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:

vector<int> findDisappearedNumbers(vector<int>& nums) {
   
    vector<int> result;
    for(int i: nums){
        int index = abs(i) - 1;
        nums[index] = -abs(nums[index]);
    }
    for(int i = 0;i < nums.size(); i++){
        if(nums[i] > 0) result.push_back(i+1);
    }
    return result;
}
};