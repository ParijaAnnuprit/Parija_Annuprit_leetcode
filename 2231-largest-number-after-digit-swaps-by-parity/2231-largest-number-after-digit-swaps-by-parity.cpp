class Solution {
public:
    int largestInteger(int num) {
        string s ="";
        priority_queue<char>even;
        priority_queue<char>odd;
        string x = to_string(num);
        for(auto i:x){
            if((i-'0')%2==0){
                even.push(i);
            }
            else{
                odd.push(i);
            }
        }
        for(auto i:x){
            if((i-'0')%2==0){
                s+=even.top();
                even.pop();
            }
            else{
                s+=odd.top();
                odd.pop();
            }
        }
        return stoi(s);
    }
};