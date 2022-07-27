// class Solution {
// public:
//     string reformat(string s) {
//         int countalp=0;
//         int countdig=0;
//         string k="";
//         vector<char>valp;
//         vector<char>vdig;
//         for(int i=0;i<s.length();i++){
//             if(isalpha(s[i])){
//                 countalp++;
//                 valp.push_back(s[i]);
//             }
//             else{
//                 countdig++;
//                 vdig.push_back(s[i]);
//             }
//         }
//         if(s.length()%2==0){
//             if(countalp!=countdig)
//                 return "";
//             else{
//                 int count=0;
//                 while(count!=s.length()){
//                     s.push_back()
//                 }
//             }
//         }
//         else if(s.length()%2!=0){
//             if(countalp>countdig && countalp+1!=countdig)
//                 return "";
//             else if(countalp<countdig && countalp!=countdig+1)
//                 return "";
//         }
//     }
// };

class Solution {
public:
    string reformat(string s) {
        string res = "";
        int alphacount = 0, numcount = 0;
        for(int i = 0; s[i]; i++){
            if(isalpha(s[i])) alphacount++;
            else numcount++;
        }
        if(abs(alphacount - numcount) > 1) return "";
        int len = s.length();
        //return to_string(len);
        int alphaptr = 0, numptr = 0;
        if(alphacount >= numcount){
            while(!(alphaptr == len && numptr == len)){
                while(isdigit(s[alphaptr])) alphaptr++;
                if(alphaptr != len) res += s[alphaptr++];
                while(isalpha(s[numptr])) numptr++;
                if(numptr != len) res += s[numptr++];
            }
        }
        else {
            while(!(alphaptr == len && numptr == len)){
                while(isalpha(s[numptr])) numptr++;
                if(numptr != len) res += s[numptr++];
                while(isdigit(s[alphaptr])) alphaptr++;
                if(alphaptr != len) res += s[alphaptr++];
            }
        }
        return res;
    }
};