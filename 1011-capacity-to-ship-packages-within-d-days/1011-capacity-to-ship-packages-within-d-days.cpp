// binary search on solution space
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
//     here remember l is the maximum of all the weights.
//         here h is the sum of all weights
        int l =0;
        int h =0;
        for(int i=0; i<n;i++){
            h = h+weights[i];
            l = max(l,weights[i]);
        }
        while(l<h){
            int m = l+((h-l)/2);
            int leftcap = m;
            int udays = 1;
            for(int j=0;j<n;j++){
                if(leftcap< weights[j]){
                    udays++;
                    leftcap = m-weights[j];
                // j--; never use this because in the last case it will go into an infinite loop
                }
                else
                    leftcap = leftcap-weights[j];
            }
            if(udays>days)
                l = m+1;
            else h =m;
        }
        return h;
    }
};