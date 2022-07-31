class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        if(s.length()==0)
            return 0;
        int len = INT_MIN;
        for(int i=0;i<s.length();i++){
            int l=0;
            for(int j=i;j<s.length();j++){
                if(st.find(s[j])!=st.end()){
                    len = max(len,l);
                    st.clear();
                    break;
                }
                else{
                    st.insert(s[j]);
                    l++;
                }
            }
            if(l>len)
                len = l;
        }
        return len;
    }
};