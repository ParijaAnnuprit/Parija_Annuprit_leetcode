// class Solution {
// public:
//     bool isLongPressedName(string name, string typed) {
//         int n = name.length();
//         int m = typed.length();
//         if(name[0]!=typed[0] || name[n-1]!=typed[m-1])
//             return false;
//         int i=1;
//         int j=1;
//         while(i<n){
//             if(name[i]!=typed[j] && typed[j]!=typed[j-1])
//                 return false;
//             if(name[i]!=typed[j] && typed[j]==typed[j-1])
//                 j++;
//             else if(name[i]==typed[j]){
//                 i++;
//                 j++;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j(1);
        if(name[0] != typed[0]) return false;
        
        for(int i = 1; i < typed.size(); i++){
            if(typed[i] != name[j] and typed[i] != name[j - 1])
                return false;
            j += typed[i] == name[j];
        }
                    
        return j == name.size();
    }
};