// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
// //  sliding window technique.
//         unordered_map<int,int>mpp;
//         for(int i=0;i<nums.size();i++){
//             if(mpp.find(nums[i])!=mpp.end()){
//                 if(abs(mpp[nums[i]]-i)<=k)
//                     return true;
//             }
//             else if(mpp.find(nums[i])==mpp.end())
//                 mpp[nums[i]]=i;
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

    unordered_map<int,int> m;
    
    for(int i=0;i<nums.size();i++)
    {
        if(m.count(nums[i]))
        {
            if(i-m[nums[i]]<=k)
                return true;
        }
        
        m[nums[i]]=i;
    }
    
    return false;
}
};