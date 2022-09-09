// class Solution {
// public:
//     bool isStrictlyPalindromic(int n) {
//         string base = "";
//         int temp = n;
//         for(int i=2;i<=n-2;i++){
//             while(temp){
//                 base = base + to_string(temp%i);
//                 temp = temp/i;
//             }
// //             for palindrome
//             for(int j=0;j<base.length();j++){
//                 if(base[j]!=base[base.length()-j+1]) return false;
//                 // else j++;
//             }
//             base.clear();
//         }
//         return true;
//     }
// };


class Solution 
{
public:
    bool isStrictlyPalindromic(int n) 
    {
        int temp;
        string base;
        for(int i=2; i<=n-2; i++)
        {
            temp=n;
            while(temp)
            {
                base = to_string(temp%i) + base;
                temp = temp/i;
            }
        
            int sz=base.size();
            for(int j=0; j<sz; j++)
            {
                if(base[j]!=base[sz-j-1])
                    return false;    
                
            }
            base.clear();
        }
        return true;
        
    }
};