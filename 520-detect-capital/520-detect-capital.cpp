class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.length();
        int uppercount = 0;
        int lowercount = 0;
        for(int i=1;i<n;i++){
            if(s[i]>=65 && s[i]<=90)
                uppercount++;
            else if(s[i]>=97 && s[i]<=122)
                lowercount++;
            }
        if(s[0]>=65 && s[0]<=90){
            if(uppercount==n-1)
                return true;
            else if(lowercount==n-1)
                return true;
            return false;
        }
        else if(s[0]>=97 && s[0]<=122){
            if(lowercount == n-1)
                return true;
        }
        return false;
    }
};