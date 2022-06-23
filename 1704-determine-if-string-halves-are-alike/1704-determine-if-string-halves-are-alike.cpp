int countvowels(string k){
    int l = k.length();
    int count = 0;
    for(int i=0;i<l;i++){
        char p = tolower(k[i]);
        if(p == 'a' ||p == 'e' ||p == 'i' ||p == 'o' ||p == 'u')
            count++;
    }
    return count;
}

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        string a = s.substr(0,n/2);
        string b = s.substr(n/2, n/2);
        if(countvowels(a)== countvowels(b))
            return true;
        return false;
    }
};