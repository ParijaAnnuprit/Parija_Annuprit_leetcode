// class Solution {
// public:
//     string reorderSpaces(string text) {
//         int n = text.length();
//         int spaces = 0;
//         int words = 0;
//         vector<string>s;
//         if(isalpha(text[0]))
//             word++;
//         for(int i=0;i<n;i++){
//             if(text[i]==' ')
//                 spaces++;
//             if(text[i]== ' ' && i<n-1 && isalpha(text[i+1]))
//                 word++;
//         }
//         int eq = spaces/(words-1);
//         int rem = spaces-(eq*(words-1));
        
//     }
// };
class Solution {
public:
    string reorderSpaces(string t) {
        
        int n=t.size();
        int spaces{0};
        string z="";
        vector<string> v;        
        for(int i=0; i<n; i++){
            if(t[i]==' '){
                spaces++;
                if(z!=""){
                    v.push_back(z);
                    z="";
                }
            }else{
                z+=t[i];
            }
        }
        
        if(t[n-1] != ' '){
            v.push_back(z);
        }
        
        int words = v.size();        
        if(words==1){
            string ec (spaces,' ');
            return v[0]+ec;
        }
        
        int gap = spaces/(words-1);
        int last_gap = spaces%(words-1);
        string g(gap, ' ');
        string gl(last_gap, ' ');
        string ans="";        
        for(int i=0; i<words-1; i++){
            ans+=v[i] + g;
        }
        
        return ans+v[words-1]+gl;   
    }
};