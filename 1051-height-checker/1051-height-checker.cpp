// class Solution {
// public:
//     int heightChecker(vector<int>& heights) {
//         int n=heights.size();
//         vector<int>v(101,0);
//         for(int i=0;i<heights.size();i++){
//             v[heights[i]]++;
//         }
//         vector<int>exp(n,0);
//         for(int i=0;i<101;i++){
//             if(v[i]!=0){
//                 while(v[i]>0){
//                     exp.push_back(i);
//                     v[i]--;
//                 }
//             }
//         }
//         int count =0;
//         for(int i=0;i<n;i++){
//             if(heights[i]!=exp[i])
//                 count++;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int>exp;
        exp=heights;
        sort(exp.begin(),exp.end());
        int count =0;
        for(int i=0;i<n;i++){
            if(heights[i]!=exp[i])
                count++;
        }
        return count;
    }
};