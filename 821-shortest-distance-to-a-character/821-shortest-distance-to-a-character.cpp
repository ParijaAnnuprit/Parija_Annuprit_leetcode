class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
//         brute force
        vector<int>ind;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]==c)
                ind.push_back(i);
        }
        int k = ind.size();
        
        vector<int>dist;
        for(int i=0;i<n;i++){
            int md = INT_MAX;
            for(int j=0;j<k;j++){
                md = min(md,abs(i-ind[j]));
            }
            dist.push_back(md);
        }
        return dist;
    }
};