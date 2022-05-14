class Solution {
public:
//     three pointer.
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size()-1;
        int maxa = 0;
        
        while(s<e){
            maxa=max(min(height[s],height[e])*(e-s), maxa);
            if(height[s]< height[e])
                s++;
            else
                e--;
            // e--;
            // if(e == s){
            //     s++;
            //     e = height.size()-1;
            // }
        }
        return maxa;
    }
};