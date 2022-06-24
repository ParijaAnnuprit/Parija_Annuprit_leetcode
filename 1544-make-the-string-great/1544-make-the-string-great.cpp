class Solution {
public:
    string makeGood(string s) {
//         brute force
        int n = s.length();
        int flag = 1;
//         since maximum no of time you can repeat the process is n/2
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<s.length();j++){
                if(s[j] == s[j+1]+32 || s[j]== s[j+1]-32){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
            else{
                for(int k=0;k<s.length();k++){
                    if(s[k] == s[k+1]+32 || s[k]== s[k+1]-32){
                        s.erase(k,2);
                    }
                }
                flag = 1;
            }
        }
        return s;
    }
};