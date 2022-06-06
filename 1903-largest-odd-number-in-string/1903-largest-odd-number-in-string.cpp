// #include<bits/stdc++.h>
// class Solution {
// public:
//     string largestOddNumber(string num) {
//         int n = num.size()-1;
//         for(int i=n; i>=0; i--){
//             if(num[i] % 2 == 0){
//                 num.pop_back();
//             }
//             return num;
//         }
//         return "0";
//     }
// };
class Solution {
public:
    string largestOddNumber(string num) {
        int l=num.size()-1;
        while(!num.empty()&&num[l--]%2==0)
            num.pop_back();
        return num;
    }
};