class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     string s = "";
    //     int minlen = 0;
    //     for(int i=0;i<strs.size();i++){
    //         int x = strs[i].length();
    //         minlen = min(minlen,x);
    //     }
    //     for(int i=0;i<minlen;i++){
    //         for(int j=0;j<strs.size();j++){
    //             if(strs[i][j]==strs[i+1][j])
    //                 continue;
    //             else
    //                 return s;
    //         }
    //         s = s+ strs[0][i];
    //     }
    //     return s;
    // }
    string longestCommonPrefix(vector<string>& strs) {
       
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string ans;
//Since we need to find the longest common prefix, we just need to compare the 0th and the last string in strs after sorting and see which characters are common. Since it's sorted, 0th & last strings' common characters will be the ans.
        string s1=strs[0];
        string s2=strs[n-1];
        
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]==s2[i])
                ans=ans+s1[i];
            else
                break;
        }
        return ans;
    }
};