class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int freq = 0.25* arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto i:mpp){
            if(i.second>freq) return i.first;
        }
        return 0;
    }
};