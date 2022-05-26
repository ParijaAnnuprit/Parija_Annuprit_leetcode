class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>arr(n,0);
        for(int i=0; i<n; i++){
            arr[i] = start+2*i;
        }
        if(n==1)
            return arr[n-1];
        else{
            for(int j=0; j<n-1; j++){
                arr[j+1] = (arr[j] ^ arr[j+1]);
            }
        }
        return arr[n-1];
    }
};