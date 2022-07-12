// class Solution {
// public:
//     int longestPalindrome(string s) {
//         unordered_map<int,int>mpp;
//         for(int i=0;i<s.length();i++){
//             if(mpp[s[i]]!=mpp.end())
//                 mpp[s[i]]++;
//             else if(mpp[s[i]]==mpp.end())
//                 mpp[s[i]]=1;
//         }
        
//     }
// };

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(auto a:s) ++freq[a];
        int ans=0;
        bool odd=false;
        for(auto a:freq){
            ans+=a.second;
            if(a.second%2 != 0) --ans, odd=true;
        }
        if(odd) ++ans;
        return ans;
    }
};