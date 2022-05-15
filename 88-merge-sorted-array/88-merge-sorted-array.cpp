class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m-1;
        int e = n-1;
        int i = m+n-1;
        while(e>=0){
            if(s>=0 && nums1[s]>nums2[e]){
                nums1[i] = nums1[s];
                s--;
                i--;
            }
            else{
                nums1[i] = nums2[e];
                e--;
                i--;
            }
        }
    }
};