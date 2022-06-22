class Solution {
public:
    int removePalindromeSub(string s) {
        int count = 1;
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s[i] != s[j]){
                return 2;
            }
            else{
                i++;
                j--;
            }
        }
        return count;
    }
};