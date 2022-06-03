class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int prev = 0;
        int ans = 0;
        int m = bank.size();
        int n = bank[0].size();
        for(int i=0; i<m; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(bank[i][j] == '1')
                    count++;
            }
            ans += prev*count;
            if(count!=0)
                prev = count;
        }
        return ans;
    }
};