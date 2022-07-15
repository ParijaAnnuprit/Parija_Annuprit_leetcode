// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
// //         store slope and frequency
//         unordered_map<int ,int>mpp;
//         int infinte = 1e9;
//         int ans = 0;
//         for(int i=0;i<points.size();i++){
//             for(int j=i+1;j<points.size();j++){
//                 int x1= points[i][0];
//                 int y1= points[i][1];
//                 int x2= points[j][0];
//                 int y2= points[j][1];
//                 if(x2==x1)
//                     mpp[infinte]++;
//                 else{
//                     int temp = abs(y2-y1)/abs(x2-x1);
//                     mpp[temp]++;
//                     ans = max(ans, mpp[temp]);
//                 }
//             }
//             mpp.clear();
//         }
//         return ans+1;
//     }
// };

class Solution {
public:
    int gcd(int a, int b){
        return b==0 ? a : gcd(b, a%b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int maxCommonPoints = 0;
        int n = points.size();
                    
        // unordered_map<string, int> freq;
        // we dont declare hashmap here because point be computed multiple time for same slope
        // ex:  [[1,1],[2,2],[3,3]]
        
        for(int i=0; i<n-1; ++i){
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            unordered_map<string, int> freq;
            
            for(int j=i+1; j<n; ++j){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dx = x2-x1;
                int dy = y2-y1;
                
                int gcdNum = gcd(dx, dy); // we find gcd to find common divisor to prevent quotient floating number
                
                dx = dx/gcdNum;// result will still be interger data type (not floating)
                dy = dy/gcdNum;
                
                string hashKey = to_string(dx) + '#' + to_string(dy);
                freq[hashKey]++;
                maxCommonPoints = max(maxCommonPoints, freq[hashKey]);
            }                                                 
        }
        
        return maxCommonPoints + 1;// we are adding one because while considering pairs of points we only counted second element
    }
};