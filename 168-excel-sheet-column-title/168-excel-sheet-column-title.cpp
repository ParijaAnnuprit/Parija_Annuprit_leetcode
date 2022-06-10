// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         string m = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
//         string res = "";
//         int x = columnNumber;
//         while(x>26){
//             res= res+ (m[x%26]);
//             x = x/26;
//         }
//         if(columnNumber>26 && columnNumber%26==0)
//             res = res+m[(x%26)-1];
//         else
//             res = res+(m[x%26]);
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };
// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         string res = "";
//         int x = columnNumber;
//         while(x){
//             int rem = (--x)%26;
//             res+= rem+ "A";
//             x = x/26;
//         }
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };
class Solution {
public:
    string convertToTitle(int c) {
        string appnd="";
        while(c) {
            int rem=(--c)%26;
            appnd+=rem+'A';
            c/=26;
        }
        reverse(appnd.begin(), appnd.end());
        return appnd;
    }
};