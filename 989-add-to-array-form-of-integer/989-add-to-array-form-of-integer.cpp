// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//         vector<int>res;
//         string m = to_string(k);
//         int diff = num.size()-m.size();
//         if(num.size()>m.size()){
//             for(int i=0;i<diff;i++){
//                 m.insert(0,"0");
//             }
//         }
//         else if(m.size()>num.size()){
//             for(int i=0;i<diff;i++){
//                 num.push_front(0);
//             }
//         }
//         int i=num.size()-1;
//         int j = m.leng()-1;
//         int carry = 0;
//         while(i>=0 || j>=0){
//             int temp = num[i]+(num[j]-'0')+carry;
//             int unit = temp%10;
//             int carry = temp/10;
//             res.push_back(unit);
//             i--;
//             j--;
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry = 0, i=num.size()-1;
        while(k && i>=0)
        {
            int digit = k%10;
            int val = num[i];
            
            num[i] = (val + digit + carry)%10;
            carry = (val + digit + carry)/10;
            
            k /= 10;
            i--;
        }
        
        while (i >= 0 && carry)
        {
            int val = num[i];
            num[i] = (val + carry) % 10;
            carry = (val + carry) / 10;
            i--;
        }        
        
        
        vector<int> res;
        
        while(k)
        {
            int digit = k%10;
            res.push_back((digit + carry)%10);
            carry = (digit + carry)/10;
            k /= 10;
        }
        
        if(carry)
            res.push_back(carry);
        
        reverse(res.begin(), res.end());
        
        res.insert(res.end(), num.begin(), num.end());
        
        return res;
        
    }
};