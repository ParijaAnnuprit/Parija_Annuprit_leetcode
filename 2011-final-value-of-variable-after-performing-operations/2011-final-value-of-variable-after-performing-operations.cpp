class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int k = 0;
        for(int i=0;i<n;i++){
            if(operations[i][0]== '-' || operations[i][2]=='-')
                k--;
            else
                k++;
        }
        return k;
    }
};