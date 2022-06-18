// class Solution {
// public:
//     string digitSum(string s, int k) {
//         int n = s.length();
//         string m = "";
//         int v = 0;
//         int l =0;
//         while(n>k){
//             for(int i=0;i<n;i++){
//                 v+=(s[i]-'0');
//                 l++;
//                 if((l==k) || ((i+1)==n)){
//                     m = m+to_string(v);
//                     v=0;
//                     l=0;
//                 }
//                 s=m;
//                 m = "";
//                 n = s.length();
//             }
//         }
//         return s;
//     }
// };
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string ns;
            for(int i=0;i<s.size();i++){
                int curr = 0;
                for(int j=i;j<i+k && j<s.size();j++)
                    curr+=(s[j]-'0');
                i=i+k-1;
                ns+=(to_string(curr));
            }
            s=ns;
        }
        return s;
    }
};
