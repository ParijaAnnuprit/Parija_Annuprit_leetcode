class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i=0; i<32; i++){
            int sumsz = 0;
            int sumso = 0;
            for(int j=0; j<n; j++){
                int k = ((nums[j]>>i)&1);
                if(k ==0){sumsz++;}
                else if(k ==1){sumso++;}
            }
            if(sumsz%3 != 0)
                res = (0<<i)|res;
            else if(sumso%3 !=0)
                res = (1<<i)|res;
        }
        return res;
    }
};