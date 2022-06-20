// class Solution {
// public:
//     int countSegments(string s) {
//         int n = s.length();
//         if(n==0)
//             return 0;
//         int count = 0;
//         for(int i=0;i<n;i++ ){
//             if(s[i]== ' ' || i==n-1)
//                 count++;
//         }
//         return count;
//     }
// };
class Solution {
public:
	int countSegments(string s) {
		if(!s.size())return 0;
		int count=0;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]!=' ' && s[i+1]==' ')count++;
		}
		if(s[s.size()-1]==' ') return count;
		return count+1;
	}
};