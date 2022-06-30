class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int countab = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='A')
                countab++;
            else if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L')
                return false;
            if(countab>=2)
                return false;
        }
        return true;
    }
};