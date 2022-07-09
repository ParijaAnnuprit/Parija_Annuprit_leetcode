bool checksingle(int n){
    if(n/10==0)
        return true;
    return false;
}
class Solution {
public:
    int addDigits(int num) {
        while(!checksingle(num)){
            int sum=0;
            while(num!=0){
                sum=sum+(num%10);
                num=num/10;
            }
            num=sum;
        }
        return num;
    }
};