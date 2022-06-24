// class Solution {
// public:
// //     brute force TC-O(n^2) SC-O(1);
//     int countWords(vector<string>& words1, vector<string>& words2) {
//         int n=words1.size(); 
//         int m = words2.size();
//         int flag = 1;
// //         for words1
//         for(int i=0;i<words1.size();i++){
//             for(int j=0;j<n;j++){
//                 if(i!=j && words1[i]==words1[j]){
//                     words1.erase(words1.begin()+j);
//                     flag = 0;
//                 }
//             }
//             if(flag==0){
//                 words1.erase(words1.begin()+i);
//                 flag=1;
//             }
//         }
// //         for words2
//         for(int i=0;i<words2.size();i++){
//             for(int j=0;j<words2.size();j++){
//                 if(i!=j && words2[i]==words2[j]){
//                     words2.erase(words2.begin()+j);
//                     flag = 0;
//                 }
//             }
//             if(flag==0){
//                 words1.erase(words1.begin()+i);
//                 flag=1;
//             }
//         }
//         int count = 0;
//         for(int i=0;i<words1.size();i++){
//             for(int j=0;j<words2.size();j++){
//                 if(words1[i]== words2[j])
//                     count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    
    int count(vector<string>&words1,string s){
         int r=0;
        for(int i=0;i<words1.size();i++){
            if(words1[i]==s){
                r++;
            }
        }
        return r;
    }

    
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp;
        for(auto x:words1){
            mp[x]++;
        }
        for(auto y:words2){
            mp[y]--;
        }
       
        
        int c=0;
        for(auto z:mp){
            if(z.second==0 && count(words1,z.first)==1){
                c++;
            }
        }
        return c ;
    }
};