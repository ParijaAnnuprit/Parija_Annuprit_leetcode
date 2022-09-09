class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](auto& a, auto& b){return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];});
        int maxdef = INT_MIN;
        int count=0;
        for(int i=properties.size()-1;i>=0;i--){
            if(properties[i][1]<maxdef) count++;
            else if(properties[i][1]>maxdef) maxdef = properties[i][1];
        }
        return count;
    }
};