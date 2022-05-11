class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        int lastnum;
        long revnum = 0;
        while(temp>0){
            lastnum = temp%10;
            revnum = revnum*10 + lastnum;
            temp = temp/10;
        }
        if(x==revnum){
            return true;
        } 
        else{
            return false;
        }
    }
};