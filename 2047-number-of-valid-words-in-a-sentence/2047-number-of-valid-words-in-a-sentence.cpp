// bool solve(string s, int m, int n){
//     int k = n-m;
//     int o=0;
//     if(s[0]== '-' || s[k-1] == '-')
//         return false;
//     else if(s[0]=='!' || s[0]=='.' || s[0]==',' || s[k-1]=='!'|| s[k-1]=='.'||s[k-1]==','){
//         for(int i=1; i<n-1; i++){
//             if(isalpha(s[i]))
//                 o++;
//         }
//         if(m==k-2)
//             return true;
//         return false;
//     }
    
//     else{
//         for(int i=0; i<n; i++){
//             if(isalpha(s[i]))
//                 o++;
//         }
//         if(o==k)
//             return true;
//     }
//     return false;
// }



// class Solution {
// public:
//     int countValidWords(string sentence) {
//         int n = sentence.length();
//         int count =0;
//         int index = 0;
//         for(int i=0; i<n; i++){
//             if(sentence[i]== ' '){
//                 if(solve(sentence, index, i))
//                     count++;
//             }
//             if(sentence[i]==' ')
//                 index = i+1;
//         }
//         return count;
//     }
// };
class Solution {
public:
// solve function will return true if word is valid else it will return false
    bool solve(string s)
    {
        int n = s.size();
		// hy variable manitains the count for hyphen
        int hy=0;
        for(int i=0;i<n;i++)
        {
		 // is alphabet we cont need to check 
            if(isalpha(s[i]))   continue;
			// if digit then return false given in question
            else if(isdigit(s[i]))   return false;
			// punctuation mark should be present only at end of character
            else if((s[i]=='.' || s[i]==',' || s[i]=='!') && i!=n-1){
                return false;
            }
			// if hyphen is present then check pre-requisite condition
            else if(s[i]=='-')
            {
                if(hy!=0 || i==0 || i==n-1 || !isalpha(s[i-1]) || !isalpha(s[i+1])) return false;
                hy++;
            }
        }
        return true;
    }
    int countValidWords(string s) {
	// using stringstram to get sting seperated by spaces
        stringstream ss(s);
        string cur;
        int cnt=0;
        while(ss>>cur)
        {
		// if solve returns true then count ++
            if(solve(cur))
            {
                cnt++;
            }
        }
        return cnt;
    }
};