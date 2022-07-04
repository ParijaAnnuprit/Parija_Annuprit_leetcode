class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(nums1[i]);
                    break;
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            for(int j=0;j<nums3.size();j++){
                if(nums2[i]==nums3[j]){
                    res.push_back(nums2[i]);
                    break;
                }
            }
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums1.size();j++){
                if(nums3[i]==nums1[j]){
                    res.push_back(nums3[i]);
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};