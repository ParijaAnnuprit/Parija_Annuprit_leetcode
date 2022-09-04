// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         unordered_map<int,int>mpp;
// //         storing the row no and the no of ones in each row row number is first and no of soldiers is second in pair
//         for(int i=0;i<mat.size();i++){
//             for(int j=0;j<mat[i].size();j++){
//                 if(mat[i][j]==1) mpp[i]++;
//             }
//         }
//         auto cmp = [](pair<int,int>& a, pair<int,int>& b){
//             return(a.second == b.second) ? a.first<b.second : a.second<b.second;
//         };
//         priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>q(cmp);
//         for(auto i:mpp){
//             q.push({i.first,i.second});
//         }
//         vector<int>v;
//         while(k>0){
//             v.push_back(q.top().first);
//             q.pop();
//             k--;
//         }
//         return v;
//     }
// };

bool cmp(pair<int,int>& a, pair<int,int>& b){
    return (a.second==b.second)? a.first<b.first : a.second<b.second;
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int>mpp;
        vector<pair<int,int>>v;
        vector<int>res;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) count++;
            }
            mpp.insert({i,count});
        }
        for(auto i:mpp){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),cmp);
        int x = v.size()-k;
        for(int i=0;i<k;i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};