class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length();
        int count = 1;
        string l = "";
        for(int i=0; i<n; i++){
            if(s[i]== ' ')
                count++;
            if(count == k && i!=n-1){
                l = s.substr(0,i+1);
            }
            else if(count == k && i==n-1)
                return s;
        }
        return l;
    }
};