class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        string k(n,'x');
        for(int i=0;i<n;i++){
            k[indices[i]] = s[i];
        }
        return k;
    }
};