class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n= allowed.length();
        int m = words.size();
        int count = m;
        int flag = 0;
        for(int i=0;i<m;i++){
            int s = words[i].size();
            for(int k=0;k<s;k++){
                for(int j = 0;j<n;j++){
                    if(words[i][k] == allowed[j]){
                        flag = 1;
                        break;
                    }
                    else
                        flag = 0;
                }
                if(flag ==0){
                    count--;
                    flag=1;
                    break;
                }
            }
        }
        return count;
    }
};