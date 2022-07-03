// class Solution {
// public:
// // brute force TC-O(n) SC-O(n)
//     vector<int> plusOne(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>res;
//         int val = 0;
//         for(int i=0;i<n;i++){
//             val =val + nums[i]*pow(10,(n-i-1));
//         }
//         val = val+1;
//         while(val!=0){
//             res.push_back(val%10);
//             val = val/10;
//         }
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };
class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1]!=9){
            nums[n-1]++;
            return nums;
        }
//         if n-1 is 9
        int carry = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=9){
                nums[i]++;
                return nums;
            }
            else if(nums[i]==9){
                nums[i]=0;
                carry=1;
            }
        }
        if(carry==1){
            nums.insert(nums.begin(),1);
        }
        return nums;
    }
};