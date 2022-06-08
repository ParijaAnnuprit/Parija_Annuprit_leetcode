class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxcount = 0;
        int n = sentences.size();
        for(int i=0; i<n; i++){
            int count = 1;
            int l = sentences[i].length();
            for(int j=0;j<l;j++){
                if(sentences[i][j]== ' ')
                    count++;
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};