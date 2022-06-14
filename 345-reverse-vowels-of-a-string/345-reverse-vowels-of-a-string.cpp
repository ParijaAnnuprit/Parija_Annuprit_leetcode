bool checkvowel(char s){
    s = tolower(s);
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')
        return true;
    return false;
}

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i=0;
        int j=n-1;
        while(i<j){
            if(checkvowel(s[i]) && checkvowel(s[j])){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
            else if(!checkvowel(s[i]) && checkvowel(s[j])){
                i++;
            }
            else if(checkvowel(s[i]) && !checkvowel(s[j]))
                j--;
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};