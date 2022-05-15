class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v;
        for(int i = 0; i<m; i++){
            v.push_back(nums1[i]);
        }
        for(int j = 0; j<n; j++){
            v.push_back(nums2[j]);
        }
        nums1.clear();
        // int s = 0;
        // int e = v.size()-1;
    //     while(s<=e){
    //         if(v[s]>v[e]){
    //             nums1.push_back(v[s]);
    //             s++;
    //         }
    //         else{
    //             nums1.push_back(v[e]);
    //             e--;
    //         }
    //     }
    //     reverse(nums1.begin(),nums1.end());
        for(int k=0; k<v.size(); k++){
            nums1.push_back(v[k]);
        }
        sort(nums1.begin(),nums1.end());
     }
};