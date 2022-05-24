class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int i = 0;
        int s = 0;
        while(i<n){
            if(i == n-1){
                nums[s] = nums[i];
                i++;
                s++;
            }
            else if(nums[i] == nums[i+1]){
                count++;
                if(count < 3){
                    i++;
                    s++;
                    nums[s] = nums[i];
                }
                else if(count>=3){
                    i++;
                    nums[s] = nums[i];
                }
            }
            else if(nums[i] != nums[i+1]){
                count = 1;
                i++;
                s++;
                nums[s] = nums[i];
            }
        }
        return s;
    }
};