class Solution {
public:
//     sqrt function TC- O(sqrt(n)*log(n)) SC-O(1).
  bool judgeSquareSum(int c) {
       for(long a=0; a*a<=c; a++){
           double b = sqrt(c-a*a);
           if(b == int(b))
               return true;
           }
      return false;
    }

// brute force TC-O(n) , SC - O(1); (two pointer approach)
  // bool judgeSquareSum(int c) {
  //       int a = 0;
  //       int b = sqrt(c);
  //       while(a<=b){
  //           long long int k = (a*a)+(b*b);
  //           if(k==c)
  //               return true;
  //           else if(k<c)
  //               a++;
  //           else
  //               b--;
  //       }
  //       return false;
  //   }
};
  