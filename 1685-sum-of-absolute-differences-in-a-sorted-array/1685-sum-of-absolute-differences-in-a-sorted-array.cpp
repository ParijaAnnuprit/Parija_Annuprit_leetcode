class Solution {
public:
//     optimal - prefix sum
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int post_sum = 0;
        for(int i=0;i<n;i++){
            post_sum = post_sum+nums[i];
        }
        int pre_sum = 0;
        vector<int>k;
        for(int j=0;j<n;j++){
            int s=0;
            s = (post_sum - pre_sum) - (n*nums[j] - 2*j*nums[j]);
            post_sum -= nums[j];
            pre_sum += nums[j];
            k.push_back(s);
        }
        return k;
    }
};

//brute force TC- O(n^2) SC- O(n) time limit exceeded for larger 'n'
    // vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    //     vector<int>x;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         int k = 0;
    //         for(int j=0;j<n;j++){
    //             k =k+ abs(nums[i]-nums[j]);
    //         }
    //        x.push_back(k);
    //     }
    //     return x;
    // }