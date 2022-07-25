// class Solution {
// public:
//     string mostCommonWord(string paragraph, vector<string>& banned) {
//         unordered_map<string,int>mpp;
//         for(int i=0;i<paragraph.size();i++){
//             if(paragraph[i]>=65 && paragraph[i]<=90)
//                 paragraph[i]= paragraph[i]+32;
//         }
//         int j=0;
//         for(int i=0;i<paragraph.size();i++){
//             if(!isalpha(paragraph[i])){
//                 string s = paragraph.substr(j,i-j);
//                 mpp[s]++;
//                 if(paragraph[i]!=' '){
//                     i=i+1;
//                     j=i+1;
//                 }
//                 else{
//                     j=i+1;
//                 }
//             }
//         }
//         for(auto s:mpp){
            
//         }
//     }
// };


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        string temp = "";
        unordered_map<string, int> mp;
        for(int i = 0; i < paragraph.size(); i++)
        {
            if(isalpha(paragraph[i]))
            {
                temp += paragraph[i];
            }
            else if(paragraph[i] == ' ' || paragraph[i] == ',')
            {
                if(temp != "")
                {
                    mp[temp]++;
                    temp = "";
                }
            }
        }
        mp[temp]++;
        temp = "";
        for(int i = 0; i < banned.size(); i++)
        {
            mp[banned[i]] = 0;
        }
        int n = INT_MIN;
        for(auto i : mp)
        {
            if(i.second > n)
            {
                temp = i.first;
                n = i.second;
            }
        }
        return temp;
    }
};