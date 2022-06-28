// class Solution {
// public:
//     string licenseKeyFormatting(string s, int k) {
//         int n = s.length();
//         int c = n;
//         string z = "";
//         for(int i=0;i<n;i++){
//             if(s[i]=='-'){
//                 c--;
//                 continue;
//             }
//             else
//                 z.push_back(s[i]);
//         }
//         string res = "";
//         int chk = c%k;
//         int grp = 0;
//         int rem =0;
//         if(chk!=0){
//             grp = grp+(c/k)+1;
//             rem = (grp*k)-c;
//         }
//         else
//             grp = grp+(c/k);
//         for(int i=0;i<c+grp-1;i++){
//             if(rem!=0){
//                 int j;
//                 for(j=0;j<rem;j++){
//                     res.push_back(z[j]);
                    
//                 }
//                 res.push_back('-');
//                 rem=0;
//                 i=j;
//             }
//             else if(rem==0){
//                 int l;
//                 for(l=i;l<k;l++){
//                     res.push_back(z[l]);
//                 }
//                 i=l;
//                 if(i==n-1)
//                     break;
//                 res.push_back('-');
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        string z = "";
        for(int i=0;i<n;i++){
            if(s[i]=='-')
                continue;
            if(s[i]>=97 && s[i]<=122){
                s[i]= s[i]-32;
                z.push_back(s[i]);
            }
            else
                z.push_back(s[i]);
        }
        int count = 0;
        for(int i=z.size()-1; i>=0;i--){
            count++;
            if(count ==k && i!=0){
                z.insert(i,"-");
                count=0;
            }
        }
        return z;
    }
};