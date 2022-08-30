// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
// //         bubble sort
//         int n = nums.size();
//         for(int i=0;i<k;i++){
//             for(int j=0;j<n-1;j++){
//                 if(nums[j]>nums[j+1])
//                     swap(nums[j],nums[j+1]);
//             }
//         }
//         return nums[n-k];
//     }
// };
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
// // selelction sort
//         int n = nums.size();
//         for(int j=n-1;j>=n-k;j--){
//             for(int i=0;i<j;i++){
//                 if(nums[i]>nums[j])
//                     swap(nums[i],nums[j]);
//             }
//         }
//         return nums[n-k];
//     }
// };
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
// priority queue
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int i=1;
        while(i<k){
            q.pop();
            ++i;
        }
        return q.top();
    }
};