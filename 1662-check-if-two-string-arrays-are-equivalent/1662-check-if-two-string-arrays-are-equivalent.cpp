class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        for(int i=0; i<n-1; i++){
            word1[i+1] = word1[i]+word1[i+1];
        }
        for(int i=0; i<m-1; i++){
            word2[i+1] = word2[i]+word2[i+1];
        }
        if(word1[n-1] == word2[m-1])
            return true;
        return false;
    }
};