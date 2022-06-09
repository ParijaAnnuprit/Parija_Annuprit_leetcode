class Solution {
public:
//     remember concatenate means in chain not random places
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        int k = 0;
        if(m>n)
            return 0;
        else if(n==m && sequence==word)
            return 1;
        for(int i=0; i<n; i++){
            int j=i; int c=0;
            while(j<n && sequence.substr(j,m)==word){
                j+=m;
                c++;
            }
            k = max(k,c);
        }
        
        return k;
    }
};
// class Solution {
// public:
//     int maxRepeating(string s, string w) {
//         int mx=0,nw=w.size(),n=s.size();
//         if(nw>n) return 0;
//         for(int i=0;i<n;i++){
//             int k=i,c=0;
//             while(k<n && s.substr(k,nw)==w){
//                 k+=nw;
//                 c++;
//             }
//             mx=max(mx,c);
//         }
//         return mx;
//     }
// };