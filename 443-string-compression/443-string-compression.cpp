// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         int ret = 0;
//         for(int i=0;i<chars.size();i++){
//             int size=1;
//             while(chars[i]==chars[i+1]){
//                 size++;
//                 i++;
//             }
//             if(size ==1){
//                 chars[ret] = chars[i];
//                 ret++;
//             }
//             else{
//                 chars[ret] = chars[i];
//                 ret++;
//                 while(size/10 != 0){
//                     chars[ret] = 'size/10';
//                     size = size%10;
//                     ret++;
//                 }
//                 chars[ret] = 'size';
//                 ret++;
//             }
//         }
//         return ret-1;
//     }
// };
class Solution{
public:
int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1){
            return 1;
        }
        string s;
        int count=1;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                count++;
            }
            else{
                if(count==1){
                    s+=chars[i-1];
                }
                else{
                    s+=chars[i-1];
                    s+=to_string(count);
                }
                count=1;
            }
        }
        if(count==1){
            s+=chars[n-1];
        }
        else{
            s+=chars[n-1];
            s+=to_string(count);
        }
        int m=s.size();
        for(int i=0;i<m;i++){
            chars[i]=s[i];
        }
        return m;
    }
};