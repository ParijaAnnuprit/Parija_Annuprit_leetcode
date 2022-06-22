// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         int n = s.length();
//         int m = t.length();
//         for(int i=0;i<n;i++){
//             if(s[i]== '#')
//                 s.erase(i-1,2);
//         }
//         for(int i=0;i<m;i++){
//             if(t[i]== '#')
//                 t.erase(i-1,2);
//         }
//         if(s==t)
//             return true;
//         return false;
//     }
// };
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();
        string k = "";
        string l = "";
        for(int i=0;i<n;i++){
            if(s[i]!= '#')
                k = k+s[i];
            else if(k.length()!=0) k.pop_back();
        }
        for(int i=0;i<m;i++){
            if(t[i]!= '#')
                l = l+t[i];
            else if(l.length()!=0) l.pop_back();
        }
        if(k==l)
            return true;
        return false;
    }
};