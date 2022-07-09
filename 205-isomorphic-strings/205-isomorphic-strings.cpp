// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         map<char,char>mpp;
//         for(int i=0;i<s.length();i++){
//             if(mpp.find(s[i])!=mpp.end()){
//                 if(t[i]!=mpp[s[i]])
//                     return false;
//             }
//             else if(mpp.find(s[i])==mpp.end()){
//                 mpp.insert({s[i],t[i]});
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
bool isIsomorphic(string s, string t) {
if(s.length()!=t.length())return false; ////condition for different length

    unordered_map<char,int>mp1;
    unordered_map<char,int>mp2;
    
    for(int i=0;i<s.length();i++)
    {
        if(mp1.find(s[i])==mp1.end() && mp2.find(t[i])==mp2.end())    ///condition for check character already exist in map or not?
        {
            mp1[s[i]]=t[i]-'a';
            mp2[t[i]]=s[i]-'a';   
        }
        else if(mp1[s[i]]!=t[i]-'a' || mp2[t[i]]!=s[i]-'a')return false;   ///if already exist then check it  mapping with correct character or not??
        
    }
    return true;
}
};