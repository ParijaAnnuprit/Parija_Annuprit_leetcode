class Solution {
public:
    int minInsertions(string s) {
        string k = "";
        int n = s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') k+=s[i];
            else if(s[i]==')' && i<n && s[i+1]==')'){
                k+=')';
                i++;
            }
            else{
                k+='*';
            }
        }
        stack<char>st;
        int count =0;
        for(int i=0;i<k.length();i++){
            if(k[i]=='(') st.push(k[i]);
            else if(!st.empty() && k[i]==')') st.pop();
            else if(st.empty() && k[i]==')') count++;
            else if(k[i]=='*' && !st.empty()){
                count++;
                st.pop();
            }
            else if(k[i]=='*' && st.empty()) count+=2;
        }
        while(!st.empty()){
            count+=2;
            st.pop();
        }
        return count;
    }
};