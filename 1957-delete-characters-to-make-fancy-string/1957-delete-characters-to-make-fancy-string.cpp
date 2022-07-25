// class Solution {
// public:
//     string makeFancyString(string s) {
// //         brute force
//         if(s.length()==1 || s.length()==2)
//             return s;
//        for(int i=0;i<s.length()-2;i++){
//            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
//                s.erase(i,1);
//                i--;
//            }
//        } 
//        return s;
//     }
// };

// class Solution {
// public:
//     string makeFancyString(string s) {
// using stack
//         int n= s.length();
//         string k = "";
//         if(s.length()==1;s.length()==2)
//             return s;
//         stack<char>st;
//         int x=0;
//         int y=1;
//         st.push(s[x]);
//         st.push(s[y]);
//         int i=2;
//         while(i<n){
//           if(s[i]==s[x] && s[i]==s[y]){
//               x++;
//               y++;
//               i++;
//           }
//           else{
//               st.push(s[i]);
//               x++;
//               y++;
//               i++;
//           }
//         }
//         while(!st.empty()){
//             k.push_back(st.top());
//             st.pop();
//         }
//         reverse(k.begin(),k.end());
//         return k;
//     }
// };


class Solution {
public:
    string makeFancyString(string s) {
        
        string ss="";
        
        int i=0;
        
        if(s.size()<3)
            
            return s;
            
        for(i=0;i<=s.length()-2;i++){
            
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                
                continue;
                
            }
            
            
            ss+=s[i];
            
        }
        
        for(int j=i;j<s.length();j++){
            
            ss+=s[j];
            
        }
        
        return ss;
        
    }

};

