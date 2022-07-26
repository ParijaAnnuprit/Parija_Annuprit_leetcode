// // vector<int>year{31,28,31,30,31,30,31,31,30,31,30,31};
// // vector<int>leap{31,29,31,30,31,30,31,31,30,31,30,31};
// bool leap(int val){
//     if((val%4==0 && val%100!=0)||(val%400==0))
//         return true;
//     return false;
// }
// // int days=0;
// int daysofyear(int year){
//     int days=0;
//     for(int i=1971;i<year;i++){
//         if(leap(i))
//             days+=366;
//         days+=365;
//     }
//     return days;
// }
// int daysofmonth(int month,int year){
//     vector<int>yr{31,28,31,30,31,30,31,31,30,31,30,31};
//     vector<int>leapyr{31,29,31,30,31,30,31,31,30,31,30,31};
//     int days=0;
//     for(int i=0;i<month;i++){
//         if(leap(year))
//             days+=leapyr[i];
//         days+=yr[i];
//     }
//     return days;
// }
// int stringtoint(string s){
//     int year = stoi(s.substr(0,4));
//     int month = stoi(s.substr(5,2));
//     int day = stoi(s.substr(8,2));
//     int totaldays = day+daysofmonth(month,year)+daysofyear(year);
//     return totaldays;
// }
// class Solution {
// public:
//     int daysBetweenDates(string date1, string date2) {
//        return abs(stringtoint(date1)-stringtoint(date2));
//     }
// };







class Solution {
public:
    //for checking if year is leap or not
    bool isLeap(int year){
        return ((year%4==0 && year%100!=0)||(year%400==0));
    }
    
    //for checking no of days in month
    int daysInMonth(int month,int year){
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            return 31;
        if(month==2)
            return isLeap(year)?29:28;
        return 30;
    }
    
    //function to calculate days from 1971 to current date
    int stringToInt(string s){
        int year=stoi(s.substr(0,4));
        int month=stoi(s.substr(5,2));
        int days=stoi(s.substr(8,2));
        
        int total_days=0;
        for(int i=1971;i<year;i++){
            total_days+=isLeap(i)?366:365;
        }
        for(int i=1;i<month;i++){
            total_days+=daysInMonth(i,year);
        }
        
        return total_days+days;
    }
    
    //main
    int daysBetweenDates(string date1, string date2) {
        return abs(stringToInt(date2)-stringToInt(date1));
        
    }
};
