class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        int l;
        vector<int>ans;
        for(int i=w;i>=1;i--){
            if(area%i==0){
                l = area/i;
                ans.push_back(l);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
