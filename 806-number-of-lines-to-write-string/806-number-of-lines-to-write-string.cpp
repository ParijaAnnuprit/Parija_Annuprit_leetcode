class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.length();
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        int sum=0;
        int count=1;
        vector<int>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<alpha.length();j++){
                // if(sum>=100){
                //     count++;
                //     sum=0;
                // }
                if(s[i]==alpha[j]){
                    if(sum+widths[j]>100){
                        count++;
                        sum=0;
                    }
                    sum=sum+widths[j];
                    break;
                }
            }
        }
        res.push_back(count);
        res.push_back(sum);
        return res;
    }
};