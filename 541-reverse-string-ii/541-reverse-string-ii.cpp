

// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         int n = s.length();
//         int l = n;
//         for(int i=0;i<n;i+=2*k){
//                 if(l/2*k>0){
//                     reverse(s.begin()+i,s.begin()+i+k);
//                     l = l-2*k;
//                 }
//                 else if(l/2*k==0){
//                     reverse(s.begin()+i,s.end());
//                 }
//         }
//         return s;
//     }
// };
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int l = n;
        for(int i=0;i<n;i+=2*k){
                if(i+k<=s.length()){
                    reverse(s.begin()+i,s.begin()+i+k);
                    l = l-2*k;
                }
                else {
                    reverse(s.begin()+i,s.end());
                }
        }
        return s;
    }
};









// class Solution {
// public:
//     string reverseStr(string s, int k) {
        
//         // size_t is unsigned int
//         //i+=k*2 here we incresase i as per given condition
        
//         for( size_t i=0;i<s.size();i+=k*2 ){
            
//             // if length is shorter then perform operation
//             // otherwise change upto i
//             if( i+k<=s.length() ){
//                 reverse(s.begin()+i,s.begin()+i+k);
//             }else{
//                 reverse(s.begin()+i,s.end());
//             }
//         }
        
//         return s;
//     }
// };