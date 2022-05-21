class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>less;
        vector<int>piv;
        vector<int>more;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot)
                less.push_back(nums[i]);
            else if(nums[i] == pivot)
                piv.push_back(nums[i]);
            else 
                more.push_back(nums[i]);
        }
        int l=0;
        int p=0;
        int m=0;
        for(int j=0; j<n; j++){
            if(l< less.size())
                nums[j] = less[l++];
            else if((l == less.size()) && (p < piv.size()))
                nums[j] = piv[p++];
            else if((l==less.size()) && (p==piv.size()) && (m<more.size()))
                nums[j] = more[m++];
        }
        return nums;
    }
};