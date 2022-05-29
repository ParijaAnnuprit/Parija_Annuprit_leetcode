class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        int m = t.length();
        int a= 0;
        for(int i=0; i<n; ++i){
            a = a^int(s[i]);
        }
        for(int j=0; j<m; ++j){
            a = a^int(t[j]);
        }
        return char(a);
    }
}; 