class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int l = n;
        vector<string>res;
        int rem = k-(n%k);
        int i=0;
        while(l>=k){
            res.push_back(s.substr(i,k));
            i+=k;
            l-=k;
        }
        if(l>0 && l<k){
            string r = s.substr(n-l,l);
            for(int j=0;j<rem;j++){
                r.push_back(fill);
            }
            res.push_back(r);
        }
        return res;
    }
};