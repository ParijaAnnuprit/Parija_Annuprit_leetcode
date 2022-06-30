class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int maxcount = 1;
        for(int i=0;i<s.length()-1;i++){
            if(s[i+1]==s[i])
                count++;
            maxcount = max(maxcount,count);
            if(s[i+1]!=s[i])
                count=1;
        }
        return maxcount;
    }
};