class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int x = 1440;
        vector<int>v;
        for(int i=0;i<timePoints.size();i++){
            int h = stoi(timePoints[i].substr(0,2))*60;
            int m = stoi(timePoints[i].substr(3,2));
            v.push_back(h+m);
        }
        sort(v.begin(),v.end());
        int a = INT_MAX;
        for(int i=1;i<v.size();i++){
            int k = v[i]-v[i-1];
            a = min(a,k);
        }
        int b = 1440-(v[v.size()-1]-v[0]);
        return min(a,b);
    }
};