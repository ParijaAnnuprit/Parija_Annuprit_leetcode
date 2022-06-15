// class Solution {
// public:
//     int romanToInt(string s) {
//         s = 'o'+s;
//         int result = 0;
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='I')
//                 result++;
//             else if(s[i]=='V'){
//                 if(s[i-1]=='I')
//                     result+=3;
//                 else
//                     result+=5;
//             }
//             else if(s[i]=='X'){
//                 if(s[i-1]=='I')
//                     result+=8;
//                 else
//                     result+=10;
//             }
//             else if(s[i]=='L'){
//                 if(s[i-1]=='X')
//                     result+=30;
//                 else
//                     result+=50;
//             }
//             else if(s[i]=='C'){
//                 if(s[i-1]=='X')
//                     result+=80;
//                 else
//                     result+=100;
//             }
//             else if(s[i]=='D'){
//                 if(s[i-1]=='C')
//                     result+=300;
//                 else
//                     result+=500;
//             }
//             else if(s[i]=='M'){
//                 if(s[i-1]=='C')
//                     result+=800;
//                 else
//                     result+=1000;
//             }
//         }
//         return result;
//     }
// };





class Solution{
public:
int romanToInt(string s){
    int result{};
    s = 'o' + s; // to prevent overflow
    for(int i = 0; i < s.size(); ++i){
        switch(s[i]){
            case 'I': ++result; continue; //nothing to explain here
            case 'V':
                switch(s[i - 1]){
                    default: result += 5; continue;
                    case 'I': result += 3; continue; //+4 -1
                }
            case 'X':
                switch(s[i - 1]){
                    default: result += 10; continue;
                    case 'I': result += 8; continue; //+9 -1
                }
            case 'L':
                switch(s[i - 1]){
                    default: result += 50; continue;
                    case 'X': result += 30; continue; //+40 -10
                }
            case 'C':
                switch(s[i - 1]){
                    default: result += 100; continue;
                    case 'X': result += 80; continue; //+90 -10
                }
            case 'D':
                switch(s[i - 1]){
                    default: result += 500; continue;
                    case 'C': result += 300; continue; //+400 -100
                }
            case 'M':
                switch(s[i - 1]){
                    default: result += 1000; continue;
                    case 'C': result += 800; continue; //+900 -100
                }
            default: continue; //for the 'o'
        }
    }
    return result;
}
};