class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for(int i=1;i<=num;i++){
            int sum = 0;
            string s = to_string(i);
            for(auto j:s){
                sum+=(j-'0');
            }
            if(sum%2==0) count++;
        }
        return count;
    }
};