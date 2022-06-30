// class Solution {
// public:
//     bool checkZeroOnes(string s) {
//         int n = s.length();
//         int count0=0;
//         int max0=0;
        
//         for(int i=0;i<n;i++){
//             if(s[i]==0){
//                 count0++;
//             }
//             else{
//                 max0=max(max0,count0);
//                 count0=0;
//             }
//         }
//         max0=max(max0,count0);
//         int count1=0;
//         int max1=0;
        
//         for(int i=0;i<n;i++){
//             if(s[i]==1){
//                 count1++;
//             }
//             else{
//                 max1=max(max1,count1);
//                 count1=0;
//             }
//         }
//         max1=max(max1,count1);
//         if(max1>max0)
//             return true;
//         return false;
//     }
// };
class Solution {
public:
	bool checkZeroOnes(string s) {
		int k1=0,k0=0;
		int max1=0,max0=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				if(k0!=0){
					max0=max(max0,k0);
					k0=0;
				}    
				k1++;
			}
			else{
				if(k1!=0){
					max1=max(max1,k1);
					k1=0;
				}    
				k0++;
			}
		}
		if(k1!=0)max1=max(max1,k1);
		if(k0!=0)max0=max(max0,k0);
		return max1>max0;
	}
};
