class Solution {
public:
    int countSegments(string s) {
        stringstream x(s);
        string k;
        int count = 0;
        while(x>>k){
            count++;
        }
        return count++;
    }
};