class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
//         binary search on solution space TC-O(nlogn) SC-O(1)
         int n =position.size();
        sort(position.begin(), position.end());
        int l = 0;
        int h = position[n-1]- position[0];
        int res =0; //res is the force between the two balls
        while(l<=h){
            int mid = l+ ((h-l)/2);
//             counting how many balls can fit with mid as its force difference
            int curr = position[0];
            int ans = 1; //ans is the number of balls in the basket
            for(int i=1;i<n;i++){
                if(position[i]-curr >= mid){
                    ans+=1;
                    curr = position[i];
                }
                if(ans>=m)
                    res = mid;
            }
//             check if the no of balls above is equal or more than prescribed
            if(ans>=m)
// avoid using l=mid because when 'l' becomes true it iterates over 'l' infinitely 
                l = mid+1; 
            else
                h = mid-1;
        }
        return res;
    }
};