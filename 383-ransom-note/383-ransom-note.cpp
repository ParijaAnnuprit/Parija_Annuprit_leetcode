class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
//         brute force
        int m = magazine.length();
        int n = ransomNote.length();
        if(m<n)
            return false;
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ransomNote[i]==magazine[j]){
                    count++;
                    magazine.erase(j,1);
                    break;
                }
            }
        }
        if(count == n)
            return true;
        return false;
    }
};