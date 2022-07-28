class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int,int>mpp;
        for(int i=0;i<ranges.size();i++){
            for(int j= ranges[i][0]; j<=ranges[i][1];j++){
                mpp[j]++;
            }
        }
        for(int i= left; i<= right;i++){
            if(mpp.find(i)==mpp.end())
                return false;
        }
        return true;
    }
};