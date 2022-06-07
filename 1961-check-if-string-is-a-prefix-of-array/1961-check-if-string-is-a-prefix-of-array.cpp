class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = words.size();
        int m = s.length();
        string k = "";
        int i =0;
        while(k.length()<=m && i<n){
            k+=words[i];
            if(k.length() <= m && k==s)
                return true;
            i++;
        }
        return false;
    }
};