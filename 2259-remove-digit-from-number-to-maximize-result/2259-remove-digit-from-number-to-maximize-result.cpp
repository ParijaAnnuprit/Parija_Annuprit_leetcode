class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        int n = number.size();
        for(int i=0; i<n;i++){
            if(number[i]== digit){
                res = max(number.substr(0,i)+number.substr(i+1),res);
            }
        }
        return res;
    }
};
        // int n = number.size();
        // int count = 0;
        // for(int i=0; i<n; i++){
        //     if(number[i] == digit)
        //         count++;
        // }
        // if(count==0)
        //     return number;
        // if(count==1){
        //     for(int i=0; i<n; i++){
        //         if(number[i] == digit){
        //             number.erase(i,1);
        //             return number;}
        //     }
        // }
        // else if(count>1){
        //     for(int i=0; i<n; i++){
        //         if(number[i]==digit && number[i]<=number[i+1]){
        //             number.erase(i,1);
        //             return number;}
        //     }}
        // return "0";