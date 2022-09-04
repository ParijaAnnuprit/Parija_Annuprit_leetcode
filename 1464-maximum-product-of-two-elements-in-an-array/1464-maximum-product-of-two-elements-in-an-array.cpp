class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i=n/2;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
    }
    void heapify(vector<int>& v, int n, int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n && v[largest]<v[l]) largest = l;
        if(r<n && v[largest]<v[r]) largest = r;
        if(largest!=i){
            swap(v[largest], v[i]);
            heapify(v,n,largest);
        }
    }
};