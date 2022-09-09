class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string base;
        int temp;
        for(int i=2;i<=n-2;i++){
            temp = n;
            while(temp){
                base = base + to_string(temp%i);
                temp = temp/i;
            }
//             for palindrome
            int s = base.size();
            for(int j=0;j<s;j++){
                if(base[j]!=base[s-j-1]) return false;
                // else j++;
            }
            base.clear();
        }
        return true;
    }
};


// class Solution 
// {
// public:
//     bool isStrictlyPalindromic(int n) 
//     {
//         int temp;
//         string base;
//         for(int i=2; i<=n-2; i++)
//         {
//             temp=n;
//             while(temp)
//             {
//                 base = to_string(temp%i) + base;
//                 temp = temp/i;
//             }
        
//             int sz=base.size();
//             for(int j=0; j<sz; j++)
//             {
//                 if(base[j]!=base[sz-j-1])
//                     return false;    
                
//             }
//             base.clear();
//         }
//         return true;
        
//     }
// };