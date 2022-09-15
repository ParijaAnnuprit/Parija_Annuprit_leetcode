class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>res;
        int k = changed.size();
        map<int,int>mpp;
        if(k%2 != 0) return res;
        for(int i=0;i<changed.size();i++){
            mpp[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++){
            int x = changed[i];
            int y = changed[i]*2;
            if(mpp.find(y)!=mpp.end() && mpp.find(x)!=mpp.end()){
                if(mpp[y]>1) mpp[y]--;
                else mpp.erase(y);
                if(mpp[x]>1){
                    mpp[x]--;
                    res.push_back(x);
                }
                else{
                    mpp.erase(x);
                    res.push_back(x);
                }
            }
        }
        if(mpp.empty()) return res;
        res.clear();
        return res;
    }
};