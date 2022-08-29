// vector<vector<int>>v;
// void backtrack(vector<int>&sub,vector<int>&m, int i, int n){
//     if(i>=n){
//         v.push_back(m);
//     }
//     m.push_back(sub[i]);
//     backtrack(sub,m,i+1,n);
//     m.pop_back();
//     backtrack(sub,m,i+1,n);
// }




// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int>m;
//         vector<int>res;
//         int max = INT_MIN;
//         backtrack(nums,m,0,n);
//         for(int i=0;i<v.size();i++){
//             if(v[i].size()==k){
//                 int sum=0;
//                 for(int j=0;j<v[i].size();j++){
//                     sum+=v[i][j];
//                 }
//                 if(sum>max)
//                     res = v[i];
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
//         min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q,s;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
            if(q.size()>k) q.pop();
        }
        while(!q.empty()){
            s.push({q.top().second,q.top().first});
            q.pop();
        }
        vector<int>f;
        while(!s.empty()){
            f.push_back(s.top().second);
            s.pop();
        }
        return f;
    }
};