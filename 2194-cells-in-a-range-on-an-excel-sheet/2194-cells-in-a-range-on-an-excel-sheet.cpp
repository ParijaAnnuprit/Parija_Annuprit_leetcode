class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>t;
        int c = int(s[0])-int(s[3]);
        int r = int(s[1])-int(s[4]);
        for(char i= s[0]; i<=s[3];i++){
            string excel = "";
            for(char j=s[1]; j<=s[4]; j++){
                excel = i;
                excel = excel+j;
                t.push_back(excel);
            }
        }
        return t;
    }
};