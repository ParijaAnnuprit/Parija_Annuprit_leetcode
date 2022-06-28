class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int b = 0;
        int e = 0;
        for(int i=0;i<n;i++){
            e=i;
            if(s[e+1] == ' ' || e==n-1){
                while(b<e){
                    swap(s[b],s[e]);
                    b++;
                    e--;
                }
                b=i+2;
            }
        }
        return s;
    }
};