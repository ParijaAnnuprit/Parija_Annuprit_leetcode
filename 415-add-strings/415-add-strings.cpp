class Solution {
public:
    string addStrings(string num1, string num2) {
        string a="";
        int i=num1.length()-1, j=num2.length()-1;
        int carry=0;
        while( i>= 0 && j>= 0){
        int temp=(num1[i--]-'0') + (num2[j--]-'0') + carry ;
        int unit=temp%10;
        carry=temp/10;
        a+= unit+'0';
        }
        while(i>=0){
        int temp=num1[i--]-'0'+carry;
        int unit=temp%10;
        carry=temp/10;
        a+=unit+'0';
        }
        while(j>=0){
        int temp=num2[j--]-'0'+carry;
        int unit=temp%10;
        carry=temp/10;
        a+=unit+'0';
        }
        if(carry) a+=carry+'0';
        reverse(a.begin(), a.end());
        return a;
    }
};