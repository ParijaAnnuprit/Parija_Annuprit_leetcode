class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxright = INT_MIN;
        if(n>1){
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    maxright = max(maxright, arr[j]);
                }
                arr[i] = maxright;
                maxright = INT_MIN;
            }
        }
        arr[n-1]=-1;
        return arr;
    }
};