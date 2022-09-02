// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         priority_queue<vector<int>>q;
//         vector<vector<int>>res;
//         for(int i=0;i<nums1.size();i++){
//             for(int j=0;j<nums2.size();j++){
//                 if(q.size()<k){
//                     vector<int>v;
//                     v.push_back(nums1[i]);
//                     v.push_back(nums2[j]);
//                     q.push(v);
//                 }
//                 else if(q.top()[0] + q.top()[1] > nums1[i]+nums2[j]){
//                     q.pop();
//                     vector<int>v;
//                     v.push_back(nums1[i]);
//                     v.push_back(nums2[j]);
//                     q.push(v);
//                 }
//             }
//         }
//         while(q.size()){
//             res.push_back(q.top());
//             q.pop();
//         }
//         return res;
//     }
// };



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int m=nums1.size(),n=nums2.size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else break;
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto p=pq.top().second;
            pq.pop();
            
            ans.push_back({p.first,p.second});
        }
        
        return ans;
    }
};