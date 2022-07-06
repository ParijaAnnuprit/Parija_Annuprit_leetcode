//we can rotate matrix clockwise by taking tanspose of matrix and then reversing each rows.
//or first reversing each columns then taking tanspose of matrix.(above one is easy)
// please upvote if you like it 
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
         bool flag;
        int n=mat.size();
        int r=4;
        //4 rotations
        while(r--){
            flag=true;
            //checking mat is equal target or not
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]!=target[i][j]){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) break;
            //rotate mat by 90°
            for(int i=0;i<n;i++){
                for(int j=0;j<=i;j++)
                    {if(i!=j)
                    swap(mat[i][j],mat[j][i]);}
            }
            for(int i=0;i<n;i++)
                reverse(mat[i].begin(),mat[i].end());
        }
        return flag;
    }
};