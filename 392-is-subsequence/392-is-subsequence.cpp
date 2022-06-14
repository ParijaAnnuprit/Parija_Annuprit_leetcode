class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int count = 0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m){
                if(s[i]==t[j]){
                    count++;
                    j++;
                    break;
                }
                else
                    j++;
            }
        }
        if(count == n)
            return true;
        return false;
    }
};