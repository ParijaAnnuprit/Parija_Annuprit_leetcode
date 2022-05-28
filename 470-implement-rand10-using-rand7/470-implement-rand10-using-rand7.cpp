// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // int x = rand7();
        // int y = rand7();
        // int val = (x-1)*y+y;
        // if(val>40)
        //     return rand10();
        // else
        //     return (val%10)+1;
        
          int num=40;
        while(num>=40){
            num=7*(rand7()-1)+rand7()-1;
        }
        
        num=num%10+1;
        return num;
    }
};