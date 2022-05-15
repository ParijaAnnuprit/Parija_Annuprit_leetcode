class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int rows = a.size();
        int cols = a[0].size();
        vector<int> dummyRow(rows,-1), dummyCol(cols,-1);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(a[i][j]==0){
                    dummyRow[i]=0;
                    dummyCol[j]=0;
                }
                
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dummyRow[i]==0 || dummyCol[j] ==0)
                    a[i][j]=0;
            }
        }
    }
};