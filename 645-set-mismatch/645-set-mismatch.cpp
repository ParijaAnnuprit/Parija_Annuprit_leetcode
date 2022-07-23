// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& arr) {
//         int i =0;
//          int n = arr.size();
//         vector<int> ans;
//          while(i<n){
//              int c_var = arr[i]-1;
//              if(arr[i]!=arr[c_var]){
//                 swap(arr[i],arr[c_var]);
//              }else{
//                 i++;
//              }
//           }
//         for(int j=0;j<n;j++){
//             if(j+1!=arr[j]){
//                 ans.push_back(arr[j]);
//                 ans.push_back(j+1);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        unordered_map<int,int>mpp;
        vector<int>res;
        for(int i=1;i<=arr.size();i++){
            mpp[i]=0;
        }
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto s:mpp){
            if(s.second==2)
                res.push_back(s.first);
        }
        for(auto s:mpp){
            if(s.second==0)
                res.push_back(s.first);
        }
        return res;
    }
};