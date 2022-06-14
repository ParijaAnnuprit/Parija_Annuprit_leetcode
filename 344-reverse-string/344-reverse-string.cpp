void rev(int i,int j, vector<char>& s){
    if(i==j || j<i)
        return ;
    swap(s[i],s[j]);
    rev(i+1,j-1,s);
}
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        rev(0,n-1,s);
    }
};

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int n = s.size();
//         int i=0;
//         int j=n-1;
//         while(i<j){
//             swap(s[i],s[j]);
//             i++;
//             j--;
//         }
//     }
// };