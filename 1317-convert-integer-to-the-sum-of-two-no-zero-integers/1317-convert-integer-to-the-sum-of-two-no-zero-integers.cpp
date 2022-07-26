bool checknozero(int x){
    string k = to_string(x);
    for(int i=0;i<k.length();i++){
        if(k[i]=='0')
            return false;
    }
    return true;
}

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>v;
        int i=1;
        int j=n-1;
        while(i<=j){
            if(checknozero(i) && checknozero(j)){
                v.push_back(i);
                v.push_back(j);
                return v;
            }
            else{
                i++;
                j--;
            }
        }
        return v;
    }
};