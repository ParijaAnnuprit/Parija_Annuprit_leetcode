class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         heap sort
        int n = nums.size();
        for(int i=n/2;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
    }
    void heapify(vector<int>& v, int i, int n){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n && v[largest]<v[l]) largest = l;
        if(r<n && v[largest]<v[r]) largest = r;
        if(largest!=i){
            swap(v[i],v[largest]);
            heapify(v,largest,n);
        }
    }
};