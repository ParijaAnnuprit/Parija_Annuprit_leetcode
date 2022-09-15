class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i]*2)!=mpp.end() && mpp.find(arr[i])!=mpp.end()){
                if(mpp[arr[i]*2]>1) mpp[arr[i]*2]--;
                else mpp.erase(arr[i]*2);
                if(mpp[arr[i]]>1) mpp[arr[i]]--;
                else mpp.erase(arr[i]);
            }
        }
        if(mpp.empty()) return true;
        return false;
    }
};