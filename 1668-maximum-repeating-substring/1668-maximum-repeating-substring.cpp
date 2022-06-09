// class Solution {
// public:
//     int maxRepeating(string sequence, string word) {
//         int n = sequence.length();
//         int m = word.length();
//         int k = 0;
//         if(m>n)
//             return 0;
//         else if(n==m && sequence==word)
//             return 1;
//         int i=0;
//         for(int i=0; i<n; i++){
//         while(i<n && sequence.substr(i,m)== word){
//             k++;
//             i+=m;
//         }
        
//         return k++;
//     }
// };
class Solution {
public:
    int maxRepeating(string s, string w) {
        int mx=0,nw=w.size(),n=s.size();
        if(nw>n) return 0;
        for(int i=0;i<n;i++){
            int k=i,c=0;
            while(k<n && s.substr(k,nw)==w){
                k+=nw;
                c++;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};