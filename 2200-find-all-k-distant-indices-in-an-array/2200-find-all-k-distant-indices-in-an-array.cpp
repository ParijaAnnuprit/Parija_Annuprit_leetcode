class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>o;
        int n = nums.size();
        for(int i=0; i<n;i++){
            int l =0;
            int h =n-1;
            for(int j=0; j<n; j++){
                if(abs(i-j)<=k  && nums[j]==key){
                    o.push_back(i);
                    break;}
            }
        }
        sort(o.begin(),o.end());
        return o;
    }
};