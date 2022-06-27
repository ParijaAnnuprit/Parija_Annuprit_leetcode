class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        int count=0;
        while(count<n){
            char x = s[0];
            s.erase(0,1);
            s.push_back(x);
            count++;
            if(s==goal)
                return true;
        }
        return false;
    }
};