class Solution {
public:
//    optimal- binary search TC- O(n^2) SC- O(1)
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        if(x<2)
            return x;
        while(l<=h){
            long long m = l + ((h-l)/2);
            long long int temp = m*m;
            if(temp>x)
                h = m-1;
            else if(temp<x)
                if((m+1)*(m+1)>x)
                    return m;
                else 
                    l = m+1;
            else if(temp == x)
                return m;
        }
        return 0;
    }
};
// class Solution {
// public:
// //    optimal- binary search TC- O(n^2) SC- O(1)
//     int mySqrt(int x) {
//         int l = 0;
//         int h = x+1;
//         while(l<h){
//             int m = l+((h-l)/2);
// //             reverse than the original ie condition matches l=m+1 and h=m since question asks maximum not minimum.
//             long long int t=m*m;
//             if(t<=x){
//                 if((m+1)*(m+1)>x || t==x)
//                     return m;
//                 l = m+1;}
//             else
//                 h = m;
//         }
//         return l-1;
//     }
// };


//     brute force TC- O(n^2) SC- O(1)
    // int mySqrt(int x) {
    //     if(x==0 || x==1)
    //         return x;
    //     for(long long int i=0; i<=x; i++){
    //         long long int y = i*i;
    //         if(y>x)
    //             return i-1;
    //     }
    //     return 0;
    // }