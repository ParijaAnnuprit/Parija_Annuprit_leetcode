// class Solution {
// public:
//     int firstUniqChar(string s) {
// //         hashmap
//         unordered_map<char,int>mpp;
//         for(int i=0;i<s.length();i++){
//             if(mpp.find(s[i])!=mpp.end()){
//                 mpp[s[i]]++;
//             }
//             else if(mpp.find(s[i])==mpp.end()){
//                 mpp[s[i]]=1;
//             }
//         }
//         char x = 'X';
//         for(auto i=mpp.begin();i!=mpp.end();i++){
//             if(i->second == 1){
//                 x=i->first;
//                 break;
//             }
//         }
//         for(int i=0;i<s.length();i++){
//             if(s[i]==x)
//                 return i;
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int>m;
        
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        
        
        for(int i=0;i<s.size();i++){
            if( m.find(s[i]) != m.end() && m[s[i]]==1) return i;
        }
        return -1;
    }
};