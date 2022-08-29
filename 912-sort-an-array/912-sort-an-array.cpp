class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
//         heap sort
        int n = nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums;
    }
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n && nums[largest]<nums[l]) largest = l;
        if(r<n && nums[largest]<nums[r]) largest = r;
        if(largest != i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
};