// class Solution {
// public:
//     int maxCount(int m, int n, vector<vector<int>>& ops) {
// o(n^3) memory limit exceeded
//         vector<vector<int>>v(m,vector<int>(n,0));
//         for(int i=0;i<ops.size();i++){
//             for(int j=0;j<ops[i][0];j++){
//                 for(int k=0;k<ops[i][1];k++){
//                     v[j][k]++;
//                 }
//             }
//         }
//         int count=0;
//         int x = v[0][0];
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(v[i][j]==x)
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int maxCount(int m, int n, vector<vector<int>>& ops) {
// //         tc = o(n) sc = o(1)
//         if(ops.size()==0)
//             return m*n;
//         int minr = INT_MAX;
//         int minc = INT_MAX;
//         for(int i=0;i<ops.size();i++){
//             minr = min(minr,ops[i][0]);
//             minc = min(minc,ops[i][1]);
//         }
//         return minr*minc; 
//     }
// };

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
//         tc = o(n) sc = o(1)
        for(auto i:ops){
            m = min(m,i[0]);
            n = min(n,i[1]);
        }
        return m*n;
    }
};