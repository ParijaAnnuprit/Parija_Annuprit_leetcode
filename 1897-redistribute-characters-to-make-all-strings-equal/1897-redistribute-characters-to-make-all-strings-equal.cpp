class Solution {
public:
    bool makeEqual(vector<string>& words) {
       int n= words.size();
        if(n==1)
            return true;
       unordered_map<char,int>mpp;
       for(int i=0;i<words.size();i++){
           for(int j=0;j<words[i].length();j++){
               mpp[words[i][j]]++;
           }
       } 
       for(auto i:mpp){
           if(i.second%n!=0)
               return false;
       }
       return true;
    }
};