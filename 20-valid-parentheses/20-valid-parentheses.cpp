// class Solution {
// public:
//     bool isValid(string s) {
//         int n = s.length();
//         int sum = 0;
//         for(int i=0;i<n;i++){
//             if(sum<0){
//                 return false;
//             }
//             if(s[i]=='(')
//                 sum = sum+1;
//             else if(s[i]==')')
//                 sum = sum-1;
//             else if(s[i]=='[')
//                 sum = sum+2;
//             else if(s[i]==']')
//                 sum = sum-2;
//             else if(s[i]=='{')
//                 sum = sum+3;
//             else if(s[i]=='}')
//                 sum = sum-3;
//         }
//         if(sum>0 || sum<0)
//             return false;
//         return true;
//     }
// };
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        vector<int>res;
        for(int i=0;i<n;i++){
            if(s[i]=='('|| s[i]=='['|| s[i]=='{')
                res.push_back(s[i]);
            else if(s[i]==')' && res.size()!=0 && res[res.size()-1]=='(')
                res.pop_back();
            else if(s[i]==']' && res.size()!=0 && res[res.size()-1]=='[')
                res.pop_back();
            else if(s[i]=='}' && res.size()!=0 && res[res.size()-1]=='{')
                res.pop_back();
            else
                return false;
        }
        if(res.size()!=0)
            return false;
        return true;
    }
};