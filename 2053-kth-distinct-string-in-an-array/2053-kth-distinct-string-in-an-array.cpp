// class Solution {
// public:
//     string kthDistinct(vector<string>& arr, int k) {
// //         brute force
//         int n = arr.size();
//         vector<int>freq(n,1);
//         for(int i=0;i<arr.size();i++){
//             for(int j=0;j<arr.size();j++){
//                 if(arr[i]==arr[j] && i!=j)
//                     freq[i]++;
//             }
//         }
//          for(int i=0;i<n;i++){
//              if(freq[i]>1)
//                  arr[i].clear();
//          }
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(count==k-1)
//                 return arr[count];
//             if(arr[i]!="")
//                 count++;
//         }
//         return "j";
//     }
// };
class Solution{
public:
string kthDistinct(vector<string>& arr, int k) {
        map<string,int> m;
        for(int i=0;i<arr.size();i++)m[arr[i]]++;
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]==1){
                k--;
                if(k==0)return arr[i];
            }
        }
        return "";
    }
};