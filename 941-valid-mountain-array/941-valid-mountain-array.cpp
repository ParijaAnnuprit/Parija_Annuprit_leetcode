class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int planes=0;
        int hill=0;
        int valley =0;
        if(n>=3 ){
            for(int i=1;i<n-1;i++){
                if(arr[i] == arr[i+1])
                    planes+=1;
                else if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                    hill+=1;
                else if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
                    valley+=1;
            }
            if(hill==1 && planes==0 && valley==0)
                return true;
        }
        return false;
    }
};
// arr[0]<arr[1] && arr[n-2]>arr[n-1]