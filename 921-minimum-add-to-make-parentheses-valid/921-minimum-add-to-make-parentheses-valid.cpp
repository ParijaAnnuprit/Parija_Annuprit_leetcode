class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int top=-1;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(top==-1 && s[i]==')')
                count++;
            else if(s[i]=='('){
                st.push(s[i]);
                top++;
            }
            else if(s[i]==')'){
                st.pop();
                top--;
            }
        }
        return count+st.size();
    }
};


// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int count1=0;
//         int count2=0;
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='(')
//                 count1++;
//             else
//                 count2++;
//         }
//         if(count1>=count2)
//             return count1-count2;
//         return count2-count1;
//     }
// };