// bool freq(vector<int>&subarr,int key){
//     unordered_map<int,int>m;
//     for(int i=0;i<subarr.size();i++){
//         m[subarr[i]]++;
//     }
//     int deg = 0;
//     for(auto i:m){
//         deg = max(deg,i.second);
//         if(deg==key)
//             return true;
//     }
//     return false;
// }
// class Solution {
// public:
   
//     int findShortestSubArray(vector<int>& nums) {
//         unordered_map<int,int>m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]++;
//         }
//         int deg = 0;
//         for(auto i:m){
//             deg = max(deg,i.second);
//         }
// //         subarrays
//         vector<int>sub;
//         int minlen=INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i;j<nums.size();j++){
//                 sub.push_back(nums[j]);
//                 if(freq(sub,deg)){
//                     int x = sub.size();
//                     minlen= min(minlen,x);
//                 }
//             }
//             sub.clear();
//         }
//         return minlen;
//     }
// };



class Solution {
public:
   
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
            int n=nums.size();
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                    m[nums[i]].push_back(i);
                    maxi=max(maxi,(int)m[nums[i]].size());//find out the maximum degree
            }
            int mini=1e9;
        for(auto it:m)
        {
                if(it.second.size()==maxi)
                {
                        mini=min(mini,it.second[maxi-1]-it.second[0]+1);//searching for minimum subarray
                }
        }
            return mini;
    }
};