// class Solution {
// public:
//     string intToRoman(int num) {
//         string res="";
//         unordered_map<int,string>m{{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
//         while(num>0){
//             for(auto i=m.begin();i!=m.end();i++){
//                 if(num/i->first>0){
//                     res+=i->second;
//                     num=num%i->first;
//                     break;
//                 }
//             }
            
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     string intToRoman(int num) {
//             // string intToRoman(int num) {
//         unordered_map<int,string> m;
//         m[1]="I";
//         m[4]="IV";
//         m[5]="V";
//         m[9]="IX";
//         m[10]="X";
//         m[40]="XL";
//         m[50]="L";
//         m[90]="XC";
//         m[100]="C";
//         m[400]="CD";
//         m[500]="D";
//         m[900]="CM";
//         m[1000]="M";
//         string res="";
//         int count=0;
//         for(auto i=m.begin();i!=m.end()&#i++){
//             int q=num/i->first;
//             num=num%i->first;
//             while(q){
//                 res+=i->second;
//                 q--;
//             }
            
//         }
//         return res;
//     }
// };
class Solution {
public:
    string intToRoman(int num) {
        vector<int> in={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        for(int i=0;i<(int)in.size();i++)
        {
            int count=num/in[i];
            while(count--)
            {
                res+=roman[i];
            }
            num=num%in[i];
        }
        return res;
    }
};
