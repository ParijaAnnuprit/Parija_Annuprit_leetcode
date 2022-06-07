// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         int n = sentence.size();
//         int m = searchWord.size();
//         int count = 1;
//         for(int i=1; i<=n-m;i++){
//             if(sentence[i] == ' ')
//                 count++;
//             else if(sentence.substr(i,m)== searchWord && (sentence[i-1]== ' ' || i == 1)){
//                     return count;
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
int isPrefixOfWord(string sentence, string searchWord) {
   int n=sentence.size();
     int re=-1;
        int s=1;
    for(int i=0;i<n;i++)
    {
        if(sentence[i]==' '){
            s++;
            continue;
        }  
        else
        {
            string r=sentence.substr(i,searchWord.size());   
            if(r==searchWord && (i==0 || sentence[i-1]==' ')){
                return s;
            }  
        }
    }
    return re;
}
};