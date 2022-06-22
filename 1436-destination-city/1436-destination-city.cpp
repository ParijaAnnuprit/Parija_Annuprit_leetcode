class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        string k = "";
        int flag = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(paths[i][1] == paths[j][0]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                return paths[i][1];
            else
                flag = 1;
        }
        return k;
    }
};