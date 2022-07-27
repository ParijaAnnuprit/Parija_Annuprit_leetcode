class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        auto cmp= [&](int a, int b ){
            return mpp[a]==mpp[b]? a>b: mpp[a]<mpp[b];
        };
        sort(nums.begin(),nums.end(),cmp);
        return nums;
    }
};








// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         map<int,int> seen;
//         for(int i=0;i<nums.size();i++)
//         {
//             seen[nums[i]]++;
//         }
//         auto cmp=[&](const int& a, const int& b)
//         {
//             return seen[a]==seen[b]? a>b: seen[a]<seen[b];
//         };//cmp
//         sort(nums.begin(),nums.end(),cmp);
//         return nums;
//     }
// };