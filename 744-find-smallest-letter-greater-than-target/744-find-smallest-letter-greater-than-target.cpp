class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        sort(letters.begin(),letters.end());
        if(target>=letters[n-1])
            return letters[0];
        for(int i=0;i<n;i++){
            if(letters[i]>target)
                return letters[i];
        }
        return 'A';
    }
};