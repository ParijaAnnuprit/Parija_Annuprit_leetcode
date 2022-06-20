// class Solution {
// public:
//     string capitalizeTitle(string s) {
//         int n = s.length();
//         for(int i=0;i<n;i++){
//             int start=0;
//             int end = 0;
//             if(s[i]== ' ' || i==n-1){
//                 end = i;
//                 if(end-start <= 2){
//                     for(int j=start;j<end;j++){
//                         if(s[j]>=65 && s[j]<=90){
//                             s[j]=s[j] + 32;
//                         }
//                     }
//                     start = i+1;
//                 }
//                 else if(end-start>2){
//                     if(s[start]>=97 && s[start]<=122){
//                             s[start]=s[start] - 32;
//                         }
//                     for(int j=start+1;j<end;j++){
//                         if(s[j]>=65 && s[j]<=90){
//                             s[j]=s[j] + 32;
//                         }
//                     }
//                     start = i+1;
//                 }
//             }
//             // else if(s[i] == n-1){
//             //     end = 
//             // }
//         }
//         return s;
//     }
// };
class Solution 
{
public:
    string capitalizeTitle(string title) 
    {
        for(int i=0;i<title.size();i++)
        {
            if((i==0 || title[i-1]==' ') && (i+1<title.size() && title[i+1]!=' ' && i+2<title.size() && title[i+2]!=' '))
            {
                title[i]=toupper(title[i]);
            }
            else
            {
                title[i]=tolower(title[i]);
            }
        }
        return title;
    }
};