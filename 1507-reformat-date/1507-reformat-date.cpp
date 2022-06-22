class Solution {
public:
    string reformatDate(string date) {
        string k = "";
        int n = date.length();
//         year
        k = k+ date.substr(n-4,4);
        k = k+ '-';
//         month
        vector<string>month{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int j = 0;
        for(int i=0;i<month.size();i++){
            if(month[i]== date.substr(n-8,3)){
                j = i+1;
                break;
            }
        }
        if(j<10){
            k = k+'0';
            k = k+ to_string(j);
            k = k+ '-';
        }
        else{
           k = k+ to_string(j);
            k = k+ '-'; 
        }
        if(!isdigit(date[1])){
            k = k+'0';
            k = k+ date[0];
        }
        else{
            k = k+date.substr(0,2);
        }
        return k;
    }
};