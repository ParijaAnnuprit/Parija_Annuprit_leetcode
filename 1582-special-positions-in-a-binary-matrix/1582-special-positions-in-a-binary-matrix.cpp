bool all_zeroes(vector<vector<int>>& mat, int row, int col){
    int r = mat.size();
    int c = mat[0].size();
    int countcolones = 0;
    int countrowones = 0;
//     for row
    for(int co=0; co<c; co++){
        if(mat[row][co] == 1){
            countrowones += 1;
        }
    }
//     for col
    for(int ro=0; ro<r; ro++){
        if(mat[ro][col] == 1){
            countcolones += 1;
        }
    }
    if(countrowones>1 || countcolones>1){
        return false;
    }
    return true;
}

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int countsp =0;
        for(int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if(mat[i][j] == 1 && all_zeroes(mat, i, j)){
                    countsp+=1;
                }
            }
        }
        return countsp;
    }
};