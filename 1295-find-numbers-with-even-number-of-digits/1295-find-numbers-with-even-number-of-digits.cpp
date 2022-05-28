class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int noeve = 0;
        for(int i=0; i<n; i++){
            while(nums[i] != 0){
                nums[i] = nums[i]/10;
                count = count+1;
            }
            if(count%2==0){
                noeve = noeve+1;
            }
            count = 0;
        }
        return noeve;
    }
};