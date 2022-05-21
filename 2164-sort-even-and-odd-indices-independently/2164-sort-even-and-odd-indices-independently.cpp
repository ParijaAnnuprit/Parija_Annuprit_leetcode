class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odd;
        vector<int>even;
        int n = nums.size();
        if(n == 0)
            return nums;
        for(int i=0; i<n; i++){
            if(i%2 != 0)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        int o = 0;
        int e = 0;
        for(int j=0; j<n; j++){
            if(j%2 == 0){
                nums[j] = even[e];
                e++;
            }
            else{
                nums[j] = odd[o];
                o++;
            }
        }
        return nums;
    }
};