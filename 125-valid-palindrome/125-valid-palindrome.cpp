class Solution {
public:
    // two pointer method
    bool isPalindrome(string s) {
            int i=0,j=s.size()-1;
    while(i<j)
    {
        if(!isalnum(s[i]))
            i++;
        else if(!isalnum(s[j]))
            j--;
        else
        {
            if(s[i]>122 or s[i]<97)
                s[i]=s[i]+32;
            if(s[j]>122 or s[j]<97)
                s[j]=s[j]+32;
            
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
    }
  return true;
}
//         int n = s.length();
//         int l = 0;
//         int h = n-1;
//         while(l<h){
//             if(isalpha(s[l]) == false)
//                 l++;
//             else if(isalpha(s[h])==false)
//                 h--;
//             else{
//                 if(s[l]>122 || s[l]<97)
//                     s[l]+=32;
//                 else if(s[h]>122 || s[h]<97)
//                     s[h]+=32;
                
//                 if(s[l] != s[h])
//                     return false;
//                 else{
//                     l++;
//                     h--;
//                 }
//             }
//         }
//         return true;
//     }
};
// class Solution {
// public:
// //     brute force method SC - O(n);
//     bool isPalindrome(string s) {
//         int n = s.length();
//         string k = "";
//         for(int i=0; i<n; i++){
//             if(isalpha(s[i])== true )
//                 k.push_back(s[i]);
//         }
//         int m = k.length();
//         int l=0;
//         int h = m-1;
//         while(l<=h){
//             if(k[l]>122 || k[l]<97)
//                 k[l]+=32;
//             else if(k[h]>122 || k[h]<97)
//                 k[h]+=32;
//             if(k[l] != k[h])
//                 return false;
//             else{
//             l++;
//             h--;}
//         }
//         return true;
//     }
// };