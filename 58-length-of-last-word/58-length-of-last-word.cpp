class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int j=n-1;
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            if(isalpha(s[i])){
                j=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==0 || (isalpha(s[i]) && s[i-1]==' ')){
                k=i;
                break;
            }
        }
        return (j-k+1);
    }
};