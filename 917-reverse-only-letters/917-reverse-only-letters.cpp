class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int b = 0;
        int e = n-1;
        while(b<e){
            if(!isalpha(s[b]))
                b++;
            else if(!isalpha(s[e]))
                e--;
            else
                swap(s[b++],s[e--]);
        }
        return s;
    }
};