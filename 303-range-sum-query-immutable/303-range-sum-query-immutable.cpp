class NumArray {
public:
    vector<int>v;
    NumArray(vector<int>& nums) {
        int sums=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sums = sums+nums[i];
            v.push_back(sums);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return v[right];
        return v[right]-v[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */ 