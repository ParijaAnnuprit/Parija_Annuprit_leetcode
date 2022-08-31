// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string,int>mpp;
//         priority_queue<pair<int,string>>q;
//         for(int i=0;i<words.size();i++){
//             mpp[words[i]]++;
//         }
//         for(auto i:mpp){
//             q.push({i.second,i.first});
//         }
//         vector<string>v;
//         while(k){
//             v.push_back(q.top().second);
//             q.pop();
//             k--;
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        unordered_map<int,vector<string>>m;
        priority_queue<pair<int,vector<string>>>q;
        vector<string>s;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }
       for(auto i:mpp){
           m[i.second].push_back(i.first);
           sort(m[i.second].begin(),m[i.second].end());
       }
        for(auto i:m){
            q.push({i.first,i.second});
        }
        while(k){
            for(int i=0;i<q.top().second.size();i++){
                if(k){
                    s.push_back(q.top().second[i]);
                    k--;
                }
            }
            q.pop();
            // k--;
        }
        return s;
    }
};