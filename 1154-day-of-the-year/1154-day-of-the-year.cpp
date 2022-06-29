// bool isleap(int year){
//     if(year%4==0)return true;
//     else if(year%100==0)return false;
//     else if(year%400==0)return true;
//     return true;
// }
// class Solution {
// public:
//     int dayOfYear(string date) {
//         int day = stoi(date.substr(8));
//         int month = stoi(date.substr(5,2));
//         int year = stoi(date.substr(0,4));
//         int leap_days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
//         int nonleap_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//         if(isleap(year)){
//             int sum = 0;
//             for(int i=0;i<month;i++){
//                 sum = sum+leap_days[i];
//             }
//             return day+sum;
//         }
//         int sum1 = 0;
//         for(int i=0;i<month;i++){
//                 sum1 = sum1+nonleap_days[i];
//             }
//         return day+sum1;
//     }
// };
 bool is_leap(int n)
    {
        if(n%400==0) return true;
        if(n%100==0) return false;
        if(n%4==0) return true;
        return false;
    }
class Solution{
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month=stoi(date.substr(5,2));
        int day = stoi(date.substr(8));
        int day_n =0;
        
        int leap_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if(is_leap(year)){
            for(int i=0;i<month;i++)
            {
                day_n+=leap_days[i];
            }
            day_n+=day;
        }else{
             for(int i=0;i<month;i++)
            {
                day_n+=days[i];
            }
            day_n+=day;
        }
        
        return day_n;
    }
};