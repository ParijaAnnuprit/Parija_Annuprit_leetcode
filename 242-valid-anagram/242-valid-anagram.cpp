class Solution {
public:
    bool isAnagram(string s, string t) {
        int l = s.length();
        int m = t.length();
        if(l!=m)
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<l;i++){
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};