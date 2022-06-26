// class Solution {
// public:
//     bool areNumbersAscending(string s) {
//         int n = s.length();
//         int x = INT_MIN;
//         for(int i=0;i<n;i++){
//             if(isdigit(s[i])){
//                 int j=i;
//                 string k ="";
//                 while(j<n && isdigit(s[j])){
//                     k = k+s[j];
//                     j++;
//                 }
//                 i = j;
//                 if(stoi(k)<x)
//                     return false;
//                 else
//                     x=stoi(k);
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        vector<int>ans; //to store all the numbers
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                string temp;
                while(i<n && isdigit(s[i]))
                {
                    temp=temp+s[i];
                    i++;
                }
                ans.push_back(stoi(temp));
            }
        }
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]>=ans[i+1])
            {
                return false;
            }
        }
        return true;
    }
};