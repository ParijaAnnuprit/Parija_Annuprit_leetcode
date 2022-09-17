// bool isempty(int x, vector<int>&temp){
//     if(x<0 || x>=temp.size()) return false;
//     else if(temp[x]==0) return true;
//     return false;
// }
// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int y = n;
//         if(flowerbed[0]==0 && isempty(1,flowerbed)){
//             flowerbed[0]=1;
//             y--;
//         }
//         if(y==0) return true;
//         if(flowerbed[flowerbed.size()-1]==0 && isempty(flowerbed.size()-2, flowerbed)){
//             flowerbed[flowerbed.size()-1]=1;
//             y--;
//         }
//         if(y==0) return true;
//         for(int i=0;i<flowerbed.size();i++){
//             if(y==0) return true;
//             if(flowerbed[i]==0 && isempty(i-1,flowerbed) && isempty(i+1,flowerbed)){
//                 flowerbed[i]=1;
//                 y--;
//             }
//         }
//         if(y==0) return true;
//         return false;
//     }
// };


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};