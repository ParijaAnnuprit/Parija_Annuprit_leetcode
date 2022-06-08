bool ispalindrome(string j){            
    int s = j.length();
    int l = 0;
    int h = s-1;
    while(l<h){
        if(j[l] == j[h]){
            l++;
            h--;
        }
        else
            return false;
    }
    return true;
}


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string k = "";
        int n = words.size();
        for(int i=0; i<n;i++){
          if( ispalindrome(words[i]))
              return words[i];
             }
        return k;
    }
};