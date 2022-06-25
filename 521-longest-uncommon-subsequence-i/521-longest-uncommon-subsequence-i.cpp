class Solution {
public:
    int findLUSlength(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(a==b){
            return -1;
        }
        else if(a.length()==b.length() && a!=b)
            return a.length();
        else if(a.length()!=b.length())
            return max(a.length(),b.length());
        return -1;
    }
};