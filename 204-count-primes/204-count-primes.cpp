class Solution {
public:
    int countPrimes(int n) {
//         sieve of eratosthenes
        vector<bool>v(n+1,true);
        v[0]= false;
        v[1]= false;
        int count =0;
        for(int i=2;i<n;i++){
            if(v[i]==true){
                count++;
               for(int j=2*i;j<n;j+=i){
                   v[j]=false;
               } 
            }
        }
        return count;
    }
};