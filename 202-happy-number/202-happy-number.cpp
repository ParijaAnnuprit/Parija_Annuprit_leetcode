int getnext(int n){
    int totalsum=0;
    while(n>0){
        int d=n%10;
        n=n/10;
        totalsum+= d*d;
    }
    return totalsum;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1 && (s.find(n)==s.end())){
            if(s.find(n)==s.end()){
                s.insert(n);
                n=getnext(n);
            }
        }
        if(n==1)
            return true;
        return false;
    }
};
    
    
// // hashset    
// class Solution {
// public:
//     unordered_set<int> s;
//     bool isHappy(int n) {
//         int ans=0;
//         while(n > 0){
//             ans += pow(n%10,2);
//             n /= 10;
//         }
//         if(ans == 1) return true;
//         else {
//             if(s.find(ans) == s.end()){
//                 s.insert(ans);
//                 return isHappy(ans);
//             }
//             return false;
//         }
//     }
// };

// // hashmap
// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_map<int,int>mp;
//         while(true){
//             int s=0;
//             while(n){
//             int temp=n%10;
//                 s+=pow(temp,2);
//                 n=n/10;
//             }
//             if(s==1)return true;
//             if(mp[s]==1)return false;
//             mp[s]++;
//             n=s;
//         }
//     }
// };