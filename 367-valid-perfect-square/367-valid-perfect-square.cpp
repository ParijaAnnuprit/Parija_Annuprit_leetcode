class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        int l =1; //constraint given nums= [1,INT_MAX-1]
        int h = num;
        while(l<=h){
            long long int m = l+((h-l)/2);
            long long int temp = m*m;
            if(temp == num)
                return true;
            else if(temp>num)
                h = m-1;
            else if(temp<num)
                if((m+1)*(m+1)>num)
                    return false;
                else
                    l = m+1;
            }
        return true;
    }
};
