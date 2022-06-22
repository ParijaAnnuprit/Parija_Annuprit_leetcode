class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.length();
        string k = "";
        for(int i=0;i<n;i++){
            if(address[i]=='.')
                k = k+ "[.]";
            else
                k = k+address[i];
        }
        return k;
    }
};