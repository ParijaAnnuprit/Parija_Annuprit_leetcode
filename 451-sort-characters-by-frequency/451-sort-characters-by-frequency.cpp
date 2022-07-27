// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int>mpp;
//         vector<char>v;
//         string k = "";
//         for(int i=0;i<s.length();i++){
//             mpp[s[i]]++;
//             v.push_back(s[i]);
//         }
//         auto cmp=[&](char a, char b){
//             return mpp[a]>=mpp[b];
//         };
//         sort(s.begin(),s.end(),cmp);
//         return s;
//     }
// };


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto i:mpp){
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string k="";
        for(int i=0;i<v.size();i++){
            while(v[i].first !=0){
                k.push_back(v[i].second);
                v[i].first--;
            }
        }
        return k;
    }
};