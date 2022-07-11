// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//         unordered_map<string,char>mpp;
//         int i=0;
//         int j=0;
//         int count=0;
//         while(j<s.length()){
//             if(s[j+1]!=' ' && j!=s.length()-1)
//                 j++;
//             else{
//                 string c = s.substr(i,j-i+1);
//                 if(mpp.find(c)!=mpp.end()){
//                     if(mpp[c]!=pattern[count])
//                         return false;
//                     else
//                         count++;
//                 }
//                 else
//                     mpp[c]=pattern[count];
//                 j=j+2;
//                 i=j;
//             }
//         }
//        return true; 
//     }
// };
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // map to get words mapped with alphabets
        unordered_map<string,char> mp;
        int count=0;
        string temp="";
        for(auto ch:s){
            if(ch==' '){
                mp[temp]=pattern[count++];
                temp="";
                continue;
            }
            temp+=ch;
        }
		// condition to check if all characters are exhausted of the patter or some are still left. if some are left then answer is false
        if(count!=pattern.size()-1)return false;
        mp[temp]=pattern[count];
        count=0; temp="";
       // map to check if a character is not mapped to multiple words else return false;
        unordered_map<char,string> p;
        for(auto i:mp ){  if(p.find(i.second)!=p.end()) return false; p[i.second]=i.first;}
       
	   //condition to check if  patterns are the same
        for(auto ch:s ){
            if(ch== ' ' ){
                cout<<temp<<pattern[count];
                if(mp[temp]==pattern[count])
                {
                    count++;
                    temp="";
                    continue;
                }
                else
                    return false;
                }
                temp+=ch;
        }
        
        return true;
        
        
    }
};