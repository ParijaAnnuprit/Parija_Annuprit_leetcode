// class Solution {
// public:
//     vector<string> findWords(vector<string>& words) {
//         int n = words.size();
//         string row1 = "qwertyiop";
//         string row2 = "asdfghjkl";
//         string row3 = "zxcvbnm";
//         vector<string>res;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<words[i].length();j++){
//                 int count = 0;
// //                 for row1
//                 for(int k=0;k<row1.length();k++){
//                     if(words[i][j] == row1[k])
//                         count++;
//                 }
//                 if(count == words[i].length()){
//                     res.push_back(words[i]);
//                     break;
//                 }
// //                 for row2
//                 count = 0;
//                 for(int k=0;k<row2.length();k++){
//                     if(words[i][j] == row2[k])
//                         count++;
//                 }
//                 if(count == words[i].length()){
//                     res.push_back(words[i]);
//                     break;
//                 }
// //                 for row3
//                 count = 0;
//                 for(int k=0;k<row1.length();k++){
//                     if(words[i][j] == row1[k])
//                         count++;
//                 }
//                 if(count == words[i].length()){
//                    res.push_back(words[i]); 
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> v;
        
        string r1 = "qwertyuiop";
        string r12 = "QWERTYUIOP";
        string r2 = "asdfghjkl";
        string r22 = "ASDFGHJKL";
        string r3 = "zxcvbnm";
        string r32 = "ZXCVBNM";
        
      for(int i=0 ; i<words.size() ; i++){
          string s1 = "";
          string s2 = "";
          string s3 = "";
            for(int j=0 ; j<words[i].length(); j++){
                if ((r1.find(words[i][j]) != std::string::npos) || (r12.find(words[i][j])!=std::string::npos)){
                    s1.push_back(words[i][j]);
                    
                }
                else if((r2.find(words[i][j])!= std::string::npos) || (r22.find(words[i][j])!=std::string::npos)){
                    s2.push_back(words[i][j]);
                    
                }
                else if((r3.find(words[i][j])!=std::string::npos) || (r32.find(words[i][j])!=std::string::npos)){
                    s3.push_back(words[i][j]);
                    
                }
            }
            if(s1==words[i] || s2==words[i] || s3==words[i]){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};