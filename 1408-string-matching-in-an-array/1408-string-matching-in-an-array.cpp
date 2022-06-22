class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>res;
        int n = words.size();
        for(int i=0;i<n;i++){
            string k = words[i];
            for(int j=0;j<n;j++){
                if(i!=j && words[j].find(k) != -1){
                    res.push_back(k);
                    break;
                }
            }
        }
        return res;
    }
};





















// class Solution {
// public:

//     vector<string> stringMatching(vector<string>& words) {
//         int n=words.size();
//         vector<string>result;
//         for(int i=0;i<n;i++)
//         {
//             string s=words[i];
//             for(int j=0;j<n;j++)
//             {
//                 if(i!=j && words[j].find(s)!=-1)
//                 {
//                     result.push_back(s);
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };