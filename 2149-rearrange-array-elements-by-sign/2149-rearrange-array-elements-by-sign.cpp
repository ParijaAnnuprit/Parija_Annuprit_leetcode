class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
        int l = nums.size();
        for(int i=0; i<l; i++){
            if(nums[i]<0)
                negative.push_back(nums[i]);
            else
                positive.push_back(nums[i]);
        }
        int p=0;
        int n=0;
        for(int j=0; j<l; j=j+2){
            nums[j] = positive[p];
            nums[j+1] = negative[n];
            p++;
            n++;
        }
        return nums;
    }
};