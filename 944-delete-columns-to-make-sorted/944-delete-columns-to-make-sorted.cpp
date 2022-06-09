// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs) {
//         int delcol = 0;
//         int n = strs.size();
//         int m = strs[0].size();
//         for(int c=0;c<m;c++){
//             for(int i=0;i<n-1;i++){
//                 if(int(strs[i][c]) > int(strs[i+1][c]) )
//                     delcol++;
//                     break;
//             }
//         }
//         return delcol;
//     }
// };
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int j=0;j<strs[0].size();j++)
        {
            for(int i=0;i<strs.size()-1;i++)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};