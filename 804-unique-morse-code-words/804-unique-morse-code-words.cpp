class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> ts {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
           
         for(int i=0;i<words.size();i++){
             string s="";
             for(int j=0;j<words[i].length();j++){
                 int zb= words[i][j];
                 s+=ts[zb-97];
             }
             words[i]=s;
         } 
        int cnt=0;
        for(int i=0;i<words.size();i++){
            
        }
        int n=words.size();
        int res = 1;
        for (int i = 1; i < n; i++) {
            int j = 0;
             for (j = 0; j < i; j++)
                   if (words[i] == words[j])
                         break;
 

                 if (i == j)
                      res++;
         }
      return res;

   }
    
};