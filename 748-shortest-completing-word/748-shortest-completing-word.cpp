// class Solution {
// public:
//     string shortestCompletingWord(string licensePlate, vector<string>& words) {
//         int n = licensePlate.length();
//         int m = words.size();
//         string k = "";
//         for(int i=0;i<n;i++){
//             if(isalpha(licensePlate[i])){
//                 k = k+tolower(licensePlate[i]);
//             }
//         }
//         string m=k;
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<k.length();j++){
//                 for(int l=0;l<words[i].size();l++){
//                     if(words[i][l]== k[j]){
//                         words[i].erase(l,1);
//                         k.erase(j,1);
//                     }
//                 }
//                 if(k.length()==0)
//                     return words[i];
//                 k=m;
//             }
//         }
//         return m;
//     }
// };
class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<string> anss;
    string temp;
    string ans;
    //erase number and space
    for (int i = 0; i < licensePlate.size(); ++i) {
      if (!(((licensePlate[i] >= '0')&&(licensePlate[i] <='9'))||(licensePlate[i]==' '))){
        temp.push_back(licensePlate[i]);
      }
    }
    //make letter to lower letter.
    for (int i = 0; i < temp.size(); ++i) {
      temp[i]= tolower(temp[i]);
    }
    string :: size_type idx;

    //push the words have all letters
    bool is_find = false;
    for (int j = 0; j < words.size(); ++j) {
        if (words[j].size()<temp.size())
          continue ;
        for (int i = 0; i < temp.size(); ++i) {
          idx = words[j].find(temp[i]);
          if (idx == string::npos){
            is_find = false;
            break ;
          }else{
            is_find = true;
          }
        }
        if (is_find){
            anss.push_back(words[j]);
        }
    }

    //check the multiple letters
    for (int i = 0; i < anss.size(); ++i) {
      string temp_str = anss[i];
      for (int j = 0; j < temp.size(); ++j) {
        idx = temp_str.find(temp[j]);
        if (idx!=string::npos){
          temp_str.erase(idx,1);
        } else{
          break ;
        }
      }

      // choose the shortest word.
      if (temp_str.size() == (anss[i].size()-temp.size())){
        if (ans == "")
          ans = anss[i];
        if (ans.size() > anss[i].size())
          ans = anss[i];
      }
    }
    return ans;
  }
};