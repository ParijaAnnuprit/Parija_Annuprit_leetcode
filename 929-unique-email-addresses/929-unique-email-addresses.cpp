// class Solution {
// public:
//     int numUniqueEmails(vector<string>& emails) {
// //         brute force
//         int n = emails.size();
//         int m;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<emails[i].length();j++){
//                 if(emails[i][j]=='@')
//                     m = j;
//                     break;
//             }
//             for(int k=0;k<=m;k++){
//                 if(emails[i][k]=='.')
//                     emails.erase(k,1);
//                 else if(emails[i][k]== '+')
//                     emails.erase(k,(m-k));
//             }
//         }
//         sort(emails.begin(),emails.end());
//         int count = 1;
//         for(int i=1;i<n;i++){
//             if(email[i] == email[i-1])
//                 continue;
//             else
//                 count++;
//         }
//         return count;
//     }
// };
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans; //Set to store unique emails
        for(string email : emails){ //Iterating over every email one by one
            int n = email.find('@'); //Finding the @ to ignore characters after
            for(int i = 0; i < n; i++){ //Iterating over every character of email
                if(email[i] == '+') { //If + is found then remove everyting after it till @/n
                    email.erase(email.begin()+i, email.begin()+n); //after + removed //Erasing after + till @
                    i = n; //Breaking the loop
                }
                else if(email[i] == '.'){ 
                    email.erase(i,1); //spaces removed //Removing if we found dot
                    n--; //As one character is deleted, @ will be move to left by one unit so decreasing n
                }
            }
            if(ans.find(email) == ans.end()) ans.insert(email); //Add in ans if its unique
        }
        return ans.size(); //Returning the size/Number of emails 
    }
};
