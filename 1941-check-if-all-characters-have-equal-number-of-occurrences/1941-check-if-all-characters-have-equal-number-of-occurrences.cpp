class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int k = m[s[0]];
        for(auto i:m){
            if(i.second != k)
                return false;
        }
        return true;
    }
};