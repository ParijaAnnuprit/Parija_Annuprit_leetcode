class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>res;
        int i = 0;
        int j = 0;
        int start = 0;
        int end = 0;
        int m = firstList.size();
        int n = secondList.size();
        if(m==0 || n==0){
            return res;
        }
        while(i<m && j<n){
            vector<int>a = firstList[i];
            vector<int>b = secondList[j];
            // not overlapping case
            if(a[1]< b[0]) i++;
            else if(b[1] < a[0]) j++;
            else{
                start = max(a[0], b[0]);
                end = min(a[1], b[1]);
                res.push_back({start, end});
                if(a[1]<= b[1]) i++;
                else if(a[1] >= b[1]) j++;
            }
        }
        return res;
    }
};