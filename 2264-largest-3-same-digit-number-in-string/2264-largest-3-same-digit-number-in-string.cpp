class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string f ="";
        int k = 0;
        for(int i=0;i<n-2;i++){
            if(num[i] == num[i+1] && num[i+1]== num[i+2]){
                string r = num.substr(i,3);
                k = max(k,stoi(r));
                f = to_string(k);
            }
        }
        if(f=="0")
            return "000";
        return f;
    }
};