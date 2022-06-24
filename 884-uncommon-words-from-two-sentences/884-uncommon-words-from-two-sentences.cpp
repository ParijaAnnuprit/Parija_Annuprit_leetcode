// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         int n = s1.length();
//         int m = s2.length();
//         vector<string>v1;
//         vector<string>v2;
//         int b = 0;
//         for(int i=0;i<n;i++){
//             if(s1[i]== ' '){
//                 v1.push_back(s1.substr(b,(i-b)));
//                 b = i+1;
//             }
//             else if(i== n-1){
//                 v1.push_back(s1.substr(b,(n-b)));
//             }
//         }
//         int a = 0;
//         for(int i=0;i<m;i++){
//             if(s2[i]== ' '){
//                 v2.push_back(s2.substr(a,(i-a)));
//                 a = i+1;
//             }
//             else if(i== m-1){
//                 v2.push_back(s2.substr(a,(m-a)));
//             }
//         }
//         int flag = 1;
// //         for v1
//         for(int i=0;i<v1.size();i++){
//             for(int j=0;j<n;j++){
//                 if(i!=j && v1[i]==v1[j]){
//                     v1.erase(v1.begin()+j);
//                     flag = 0;
//                 }
//             }
//             if(flag==0){
//                 v1.erase(v1.begin()+i);
//                 flag=1;
//             }
//         }
// //         for words2
//         for(int i=0;i<v2.size();i++){
//             for(int j=0;j<v2.size();j++){
//                 if(i!=j && v2[i]==v2[j]){
//                     v2.erase(v2.begin()+j);
//                     flag = 0;
//                 }
//             }
//             if(flag==0){
//                 v2.erase(v2.begin()+i);
//                 flag=1;
//             }
//         }
//         vector<string>res;
//         for(int i=0;i<v1.size();i++){
//             for(int j=0;j<v2.size();j++){
//                 if(v1[i]!= v2[j])
//                     res.push_back(v1[i]);
//             }
//         }
//         for(int i=0;i<v2.size();i++){
//             for(int j=0;j<v1.size();j++){
//                 if(v2[i]!= v1[j])
//                     res.push_back(v2[i]);
//             }
//         }
//         return res;
//     }
// };
            class Solution {
public:
vector<string> uncommonFromSentences(string s1, string s2) {
  vector<string>ans;
   unordered_map<string,int>m;
    int n1=s1.size();
    int n2=s2.size();
    string temp="";
    for(int i=0;i<n1;i++){
       if(s1[i]!=' '){
         temp+=s1[i];  
       }
        else{
            m[temp]++;//use map for storing a string and its count
            temp="";
        }
    }
    m[temp]++;
    string temp1="";
      for(int i=0;i<n2;i++){
       if(s2[i]!=' '){
         temp1+=s2[i];  
       }
        else{
            m[temp1]++;
            temp1="";
        }
    }
    m[temp1]++;
    for(auto x:m){
        if(x.second==1){// it is nessesary for a string that its count is only 1
            ans.push_back(x.first);
        }
    }
    
    return ans;
    
}
};