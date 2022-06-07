class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();
        int m = s.length();
        int count = 0;
        for(int i=0;i<n;i++){
            int k = words[i].length();
            if(k<=m && words[i] == s.substr(0,k))
                count++;
        }
        return count;
    }
};