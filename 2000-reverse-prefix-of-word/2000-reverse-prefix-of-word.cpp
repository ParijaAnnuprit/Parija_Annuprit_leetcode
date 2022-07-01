class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                int k=0;
                int l=i;
                while(k<l){
                    swap(word[k],word[l]);
                    k++;
                    l--;
                }
                break;
            }
        }
        return word;
    }
};